#include "LongestValidParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestValidParentheses, Solution32_1) {
  auto S32_1 = Solution32_1();

  EXPECT_EQ(2, S32_1.longestValidParentheses("(()"));
  EXPECT_EQ(4, S32_1.longestValidParentheses(")()())"));
  EXPECT_EQ(0, S32_1.longestValidParentheses(""));
}

TEST(LongestValidParentheses, Solution32_2) {
  auto S32_2 = Solution32_2();

  EXPECT_EQ(2, S32_2.longestValidParentheses("(()"));
  EXPECT_EQ(4, S32_2.longestValidParentheses(")()())"));
  EXPECT_EQ(0, S32_2.longestValidParentheses(""));
}

TEST(LongestValidParentheses, Solution32_3) {
  auto S32_3 = Solution32_3();

  EXPECT_EQ(2, S32_3.longestValidParentheses("(()"));
  EXPECT_EQ(4, S32_3.longestValidParentheses(")()())"));
  EXPECT_EQ(0, S32_3.longestValidParentheses(""));
}
