#!/usr/bin/env sh

_WORK_DIR="$(dirname "$0")"
_CACHE_DIR="$_WORK_DIR/.cache"
[ -d "$_CACHE_DIR" ] || mkdir "$_CACHE_DIR"
_ALL="$_CACHE_DIR/all"

_UA="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"

# shellcheck disable=SC2016
_DATA='{"operationName":"questionData","variables":{"titleSlug":"two-sum"},"query":"query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    envInfo\n    libraryUrl\n    __typename\n  }\n}\n"}'

_is_integer() {
  [ -n "$1" ] && [ "$1" -eq "$1" ] 2>/dev/null
}

_error() { echo "$@" >&2; }

_exist() { command -v "$1" >/dev/null 2>&1; }

for t in curl jq; do
  if ! _exist "$t"; then
    _error "'$t' not found"
    return 1
  fi
done

for t in html2text clang-format; do
  _exist "$t" || _error "'$t' not found, some functions may not work"
done

_get_slug_by_id() {
  if [ ! -f "$_ALL" ] || ! grep -sq "^$1 " "$_ALL"; then
    curl -fsSL --compressed -A "$_UA" https://leetcode.com/api/problems/all/ |
      jq -r '.stat_status_pairs[].stat | "\(.frontend_question_id) \(.question__title_slug)"' |
      sort -n >"$_ALL"
  fi
  # sed -n "$1p" "$ALL"
  grep "^$1 " "$_ALL" | awk '{print $2}'
}

_retrieve_data() {
  _data=$(printf "%s\n" "$_DATA" | jq -c ".variables.titleSlug = \"$1\"")
  curl -fsSL --compressed -A "$_UA" -X POST -d "$_data" \
    -H "Content-Type: application/json" \
    https://leetcode.com/graphql
}

_expect_no_files() {
  _ret=0
  for f in "$@"; do
    if [ -f "$f" ]; then
      _ret=1
      _error "'$f' already exists"
    fi
  done
  return $_ret
}

gen_snippet_c() {
  if [ $# -ne 1 ]; then _error "Specify an id or slug" && return 1; fi
  _slug="$1"
  _is_integer "$_slug" && _slug=$(_get_slug_by_id "$1")
  _fn=$(echo "$_slug" | tr '-' '_')
  _header="$_WORK_DIR/c/include/$_fn.h"
  _src="$_WORK_DIR/c/src/$_fn.c"
  _test="$_WORK_DIR/c/tests/${_fn}_test.cpp"
  if ! _expect_no_files "$_header" "$_src" "$_test"; then
    _error "Remove them to regenerate"
    return 1
  fi

  [ -f "$_CACHE_DIR/$_slug.json" ] || _retrieve_data "$_slug" >"$_CACHE_DIR/$_slug.json"
  _content=$(jq -r '.data.question.content' "$_CACHE_DIR/$_slug.json" | html2text -ascii -nobs)
  _macro="$(echo "$_fn" | tr '[:lower:]' '[:upper:]')"
  _id=$(jq -r '.data.question.questionFrontendId' "$_CACHE_DIR/$_slug.json")
  _snippet=$(jq -r '.data.question.codeSnippets | .[] | select(.langSlug=="c") | .code' "$_CACHE_DIR/$_slug.json" | clang-format)
  # TODO: handle design questions

  cat <<END >"$_header"
/*
$(echo "$_content" | sed -e 's/^/ * /g' -e 's/^ \* *$/ */g')
 */

#ifndef LEETCODE_${_macro}_H
#define LEETCODE_${_macro}_H

$(echo "$_snippet" | sed -e "s/ \([^[:space:]]*\)(/ \1_${_id}_1(/" -e 's/ {}$/;/')

#endif //LEETCODE_${_macro}_H
END
  cat <<END >"$_src"
#include "$(basename "$_header")"

$(echo "$_snippet" | sed -e "s/ \([^[:space:]]*\)(/ \1_${_id}_1(/")
END
  cat <<END >"$_test"
#include <gtest/gtest.h>

extern "C" {
#include "$(basename "$_header")"
}

TEST(${_fn}_test, ${_fn}_1) {}
END
  clang-format -i "$_header" "$_src" "$_test"
  _error ">> '$_header'"
  _error ">> '$_src'"
  _error ">> '$_test'"
}

_fn_cpp() {
  _rest="${1%-*}"
  _last="${1##*-}"
  [ "$_rest" = "$_last" ] && _last=
  _rest=$(echo "$_rest" | awk -F '-' '{ for(i=1;i<=NF;i++){ $i = toupper(substr($i,1,1)) substr($i,2) } print }' OFS='')
  if echo "$_last" | grep -sq '^[ivx]*$'; then # roughly determine if it is a Roman numeral
    _last=$(echo "$_last" | tr '[:lower:]' '[:upper:]')
  else
    _last=$(echo "$_last" | awk '{ first = substr($0, 1, 1); upper = toupper(first); $0 = upper substr($0, 2); print }')
  fi
  echo "$_rest$_last"
}

gen_snippet_cpp() {
  if [ $# -ne 1 ]; then _error "Specify an id or slug" && return 1; fi
  _slug="$1"
  _is_integer "$_slug" && _slug=$(_get_slug_by_id "$1")
  _fn=$(_fn_cpp "$_slug")
  _header="$_WORK_DIR/cpp/include/$_fn.h"
  _src="$_WORK_DIR/cpp/src/$_fn.cpp"
  _test="$_WORK_DIR/cpp/tests/${_fn}Test.cpp"
  if ! _expect_no_files "$_header" "$_src" "$_test"; then
    _error "Remove them to regenerate"
    return 1
  fi

  [ -f "$_CACHE_DIR/$_slug.json" ] || _retrieve_data "$_slug" >"$_CACHE_DIR/$_slug.json"
  _content=$(jq -r '.data.question.content' "$_CACHE_DIR/$_slug.json" | html2text -ascii -nobs)
  _macro="$(echo "$_fn" | tr '[:lower:]' '[:upper:]')"
  _id=$(jq -r '.data.question.questionFrontendId' "$_CACHE_DIR/$_slug.json")
  _snippet=$(jq -r '.data.question.codeSnippets | .[] | select(.langSlug=="cpp") | .code' "$_CACHE_DIR/$_slug.json" | clang-format)
  _class=$(echo "$_snippet" | sed -n 's/^class \(.*\) {$/\1/p')

  cat <<END >"$_header"
$(echo "$_content" | sed 's|^|// |g')

#ifndef LEETCODECPP_${_macro}_H
#define LEETCODECPP_${_macro}_H

namespace lcpp {

$(echo "$_snippet" | sed -e "s/^class Solution/class Solution${_id}_1/" -e 's/ {}$/;/g')

} // namespace lcpp

#endif // LEETCODECPP_${_macro}_H
END

  cat <<END >"$_src"
#include "$(basename "$_header")"

using namespace lcpp;

$(echo "$_snippet" | sed -e 's/^class .* {$//' \
    -e 's/public://' \
    -e "s/^  $_class(.*$//" \
    -e 's/^};$//' \
    -e "s/ \([^[:space:]]*(\)/ $_class::\1/" \
    -e "s/Solution/Solution${_id}_1/")
END

  cat <<END >"$_test"
#include "$(basename "$_header")"
#include "gtest/gtest.h"

using namespace lcpp;

END
  if [ "$_class" = 'Solution' ]; then
    echo "TEST($_fn, Solution${_id}_1) { auto S${_id}_1 = Solution${_id}_1(); }" >>"$_test"
  else
    echo "TEST($_fn, Solution${_id}_1) {}" >>"$_test"
  fi

  clang-format -i "$_header" "$_src" "$_test"
  _error ">> '$_header'"
  _error ">> '$_src'"
  _error ">> '$_test'"
}

_arabic_to_en() {
  echo "$@" |
    sed 's/0/zero/; s/1/one/; s/2/two/; s/3/three/; s/4/four/; s/5/five/; s/6/six/; s/7/seven/; s/8/eight/; s/9/nine/'
}

_legalize_slug() {
  _first_char=$(echo "$1" | cut -c 1)
  if _is_integer "$_first_char"; then
    if _is_integer "$(echo "$1" | cut -c 2)"; then
      # Unable to handle multiple leading digits
      # Let's hope this won't happen
      return 1
    else
      echo "$(_arabic_to_en "$_first_char")$(echo "$1" | cut -c 2-)"
    fi
  else
    echo "$1"
  fi
}

gen_snippet_java() {
  if [ $# -ne 1 ]; then _error "Specify an id or slug" && return 1; fi
  _slug="$1"
  _is_integer "$_slug" && _slug=$(_get_slug_by_id "$1")
  __slug=$(_legalize_slug "$_slug")
  if [ -z "$__slug" ]; then
    error "Unable to handle slug '$_slug' for java"
    return 1
  fi
  _fn=$(_fn_cpp "$__slug") # same as cpp
  _src="$_WORK_DIR/java/src/main/java/io/binac/leetcode/$_fn.java"
  _test="$_WORK_DIR/java/src/test/java/io/binac/leetcode/${_fn}Test.java"
  if ! _expect_no_files "$_src" "$_test"; then
    _error "Remove them to regenerate"
    return 1
  fi

  [ -f "$_CACHE_DIR/$_slug.json" ] || _retrieve_data "$_slug" >"$_CACHE_DIR/$_slug.json"
  _content=$(jq -r '.data.question.content' "$_CACHE_DIR/$_slug.json") # in html
  _id=$(jq -r '.data.question.questionFrontendId' "$_CACHE_DIR/$_slug.json")
  _snippet=$(jq -r '.data.question.codeSnippets | .[] | select(.langSlug=="java") | .code' "$_CACHE_DIR/$_slug.json")
  _class=$(echo "$_snippet" | sed -n 's/^class \(.*\) {$/\1/p')

  cat <<END >"$_src"
package io.binac.leetcode;

/**
$(echo "$_content" | sed -e 's/^/ * /g' -e 's/^ \* *$/ */g')
 */
public class $_fn {
$(echo "$_snippet" | sed -e 's/^class/public static class/' \
    -e 's/class Solution/public static class Solution1/' -e 's/^/    /g')
}
END

  cat <<END >"$_test"
package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ${_fn}Test {
END
  if [ "$_class" = Solution ]; then
    cat <<END >>"$_test"
    private static final ${_fn}.Solution1 SOLUTION1 = new ${_fn}.Solution1();
END
  fi
  cat <<END >>"$_test"

    @Test
    void test1() {
    }
}
END
  _error ">> '$_src'"
  _error ">> '$_test'"
}

gen_snippet_python3() {
  if [ $# -ne 1 ]; then _error "Specify an id or slug" && return 1; fi
  _slug="$1"
  _is_integer "$_slug" && _slug=$(_get_slug_by_id "$1")
  __slug=$(_legalize_slug "$_slug")
  if [ -z "$__slug" ]; then
    error "Unable to handle slug '$_slug' for python3"
    return 1
  fi
  _fn=$(echo "$__slug" | tr '-' '_')
  _src="$_WORK_DIR/python3/leetcodepy/$_fn.py"
  _test="$_WORK_DIR/python3/tests/test_$_fn.py"
  if ! _expect_no_files "$_src" "$_test"; then
    _error "Remove them to regenerate"
    return 1
  fi

  [ -f "$_CACHE_DIR/$_slug.json" ] || _retrieve_data "$_slug" >"$_CACHE_DIR/$_slug.json"
  _content=$(jq -r '.data.question.content' "$_CACHE_DIR/$_slug.json" | html2text -ascii -nobs)
  _id=$(jq -r '.data.question.questionFrontendId' "$_CACHE_DIR/$_slug.json")
  _snippet=$(jq -r '.data.question.codeSnippets | .[] | select(.langSlug=="python3") | .code' "$_CACHE_DIR/$_slug.json")
  _class=$(echo "$_snippet" | sed -n 's/^class \(.*\):$/\1/p')

  cat <<END >"$_src"
"""
$(echo "$_content" | sed 's/^ *$//g')
"""


$(echo "$_snippet" | sed 's/class Solution/class Solution1/')
END

  cat <<END >"$_test"
from unittest import TestCase

from leetcodepy.$_fn import *
END
  if [ "$_class" = Solution ]; then
    cat <<END >>"$_test"

SOLUTION1 = Solution1()
END
  fi
  cat <<END >>"$_test"


class Test$(_fn_cpp "$_slug")(TestCase):
    def test1(self):
END
  _error ">> '$_src'"
  _error ">> '$_test'"
  # autopep8 -i "$_src" "$_test"
}

gen_snippets() {
  if [ $# -ne 1 ]; then _error "Specify an id or slug" && return 1; fi
  gen_snippet_c "$1"
  gen_snippet_cpp "$1"
  gen_snippet_java "$1"
  gen_snippet_python3 "$1"
}

gen_clean_cache() {
  rm -rf "$_CACHE_DIR:?"/*
}

_error "Source this script to use the following functions:"
sed -n 's/^\([a-z][a-z_]*\)().*$/\1/p' "$0"
