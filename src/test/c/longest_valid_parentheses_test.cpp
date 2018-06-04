#include <gtest/gtest.h>

extern "C" {
#include "longest_valid_parentheses.h"
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_1) {
    EXPECT_EQ(longestValidParentheses_32_1("(()"), 2);
    EXPECT_EQ(longestValidParentheses_32_1(")()())"), 4);
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_2) {
    EXPECT_EQ(longestValidParentheses_32_2("(()"), 2);
    EXPECT_EQ(longestValidParentheses_32_2(")()())"), 4);
}

TEST(longest_valid_parentheses_test, longestValidParentheses_32_3) {
    EXPECT_EQ(longestValidParentheses_32_3("(()"), 2);
    EXPECT_EQ(longestValidParentheses_32_3(")()())"), 4);
}
