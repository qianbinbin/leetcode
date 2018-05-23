#include <gtest/gtest.h>

extern "C" {
#include "regular_expression_matching.h"
}

TEST(regular_expression_matching_test, isMatch_10_1) {
    EXPECT_FALSE(isMatch_10_1("aa", "a"));
    EXPECT_TRUE(isMatch_10_1("aa", "a*"));
    EXPECT_TRUE(isMatch_10_1("ab", ".*"));
    EXPECT_TRUE(isMatch_10_1("aab", "c*a*b"));
    EXPECT_FALSE(isMatch_10_1("mississippi", "mis*is*p*."));
}