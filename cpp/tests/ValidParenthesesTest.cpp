#include "ValidParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidParentheses, Solution20_1) {
  auto S20_1 = Solution20_1();

  EXPECT_TRUE(S20_1.isValid("()"));
  EXPECT_TRUE(S20_1.isValid("()[]{}"));
  EXPECT_FALSE(S20_1.isValid("(]"));
  EXPECT_FALSE(S20_1.isValid("([)]"));
  EXPECT_TRUE(S20_1.isValid("{[]}"));
}