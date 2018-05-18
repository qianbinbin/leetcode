#include <gtest/gtest.h>

extern "C" {
#include <word_break.h>
}

TEST(leetcode_139, normal) {
    char *dict1[] = {"leet", "code"};
    EXPECT_TRUE(wordBreak_139("leetcode", dict1, 2));
    char *dict2[] = {"apple", "pen"};
    EXPECT_TRUE(wordBreak_139("applepenapple", dict2, 2));
    char *dict3[] = {"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(wordBreak_139("catsandog", dict3, 5));
    char *dict4[] = {"a", "abc", "b", "cd"};
    EXPECT_TRUE(wordBreak_139("abcd", dict4, 4));
}
