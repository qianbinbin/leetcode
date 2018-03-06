#include <gtest/gtest.h>

extern "C" {
#include <regular-expression-matching.h>
}

TEST(leetcode_10, normal) {
    EXPECT_FALSE(isMatch_10("aa", "a"));
    EXPECT_TRUE(isMatch_10("aa", "aa"));
    EXPECT_FALSE(isMatch_10("aaa", "aa"));
    EXPECT_TRUE(isMatch_10("aa", "a*"));
    EXPECT_TRUE(isMatch_10("aa", ".*"));
    EXPECT_TRUE(isMatch_10("ab", ".*"));
}