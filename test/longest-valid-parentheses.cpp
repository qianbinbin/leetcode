#include <gtest/gtest.h>

extern "C" {
#include <longest-valid-parentheses.h>
}

TEST(leetcode_32_1, normal) {
    EXPECT_EQ(longestValidParentheses_32_1("(()"), 2);
    EXPECT_EQ(longestValidParentheses_32_1(")()())"), 4);
    EXPECT_EQ(longestValidParentheses_32_1("(((())))()())"), 12);
    EXPECT_EQ(longestValidParentheses_32_1(")))"), 0);
    EXPECT_EQ(longestValidParentheses_32_1(")))((())"), 4);
    EXPECT_EQ(longestValidParentheses_32_1(")(((((()())()()))()(()))("), 22);
}
