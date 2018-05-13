#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <substring-with-concatenation-of-all-words.h>
}

TEST(leetcode_30, normal) {
    char *words[] = {"foo", "bar"};
    int size = 0;
    int *starts = findSubstring_30("barfoothefoobarman", words, 2, &size);
    array_print(starts, size);
    free(starts);
}

TEST(leetcode_30, empty) {
    char *words[] = {"a"};
    int size = 0;
    int *starts = findSubstring_30("", words, 1, &size);
    array_print(starts, size);
    free(starts);
}
