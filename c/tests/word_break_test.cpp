#include <gtest/gtest.h>

extern "C" {
#include "word_break.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(word_break_test, wordBreak_139_1) {
    char *s1 = "leetcode";
    char *word_dict1[] = {"leet", "code"};
    EXPECT_TRUE(wordBreak_139_1(s1, word_dict1, ARR_SIZE(word_dict1)));

    char *s2 = "applepenapple";
    char *word_dict2[] = {"apple", "pen"};
    EXPECT_TRUE(wordBreak_139_1(s2, word_dict2, ARR_SIZE(word_dict2)));

    char *s3 = "catsandog";
    char *word_dict3[] = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(wordBreak_139_1(s3, word_dict3, ARR_SIZE(word_dict3)));
}
