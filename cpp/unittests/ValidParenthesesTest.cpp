#include "ValidParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidParentheses, Solution20_1) {
  EXPECT_TRUE(Solution20_1().isValid("()"));
  EXPECT_TRUE(Solution20_1().isValid("()[]{}"));
  EXPECT_FALSE(Solution20_1().isValid("(]"));
  EXPECT_FALSE(Solution20_1().isValid("([)]"));
  EXPECT_TRUE(Solution20_1().isValid("{[]}"));
}