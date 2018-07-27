#include <gtest/gtest.h>

extern "C" {
#include "word_break.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

char *s1 = "leetcode";
char *dict1[] = {"leet", "code"};

char *s2 = "applepenapple";
char *dict2[] = {"apple", "pen"};

char *s3 = "catsandog";
char *dict3[] = {"cats", "dog", "sand", "and", "cat"};

TEST(word_break_test, wordBreak_139_1) {
    EXPECT_TRUE(wordBreak_139_1(s1, dict1, ARR_SIZE(dict1)));
    EXPECT_TRUE(wordBreak_139_1(s2, dict2, ARR_SIZE(dict2)));
    EXPECT_FALSE(wordBreak_139_1(s3, dict3, ARR_SIZE(dict3)));
}
