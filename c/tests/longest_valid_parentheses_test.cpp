#include <gtest/gtest.h>

extern "C" {
#include "longest_valid_parentheses.h"
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_1) {
    EXPECT_EQ(2, longestValidParentheses_32_1("(()"));
    EXPECT_EQ(4, longestValidParentheses_32_1(")()())"));
    EXPECT_EQ(0, longestValidParentheses_32_1(""));
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_2) {
    EXPECT_EQ(2, longestValidParentheses_32_2("(()"));
    EXPECT_EQ(4, longestValidParentheses_32_2(")()())"));
    EXPECT_EQ(0, longestValidParentheses_32_2(""));
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_3) {
    EXPECT_EQ(2, longestValidParentheses_32_3("(()"));
    EXPECT_EQ(4, longestValidParentheses_32_3(")()())"));
    EXPECT_EQ(0, longestValidParentheses_32_3(""));
}
