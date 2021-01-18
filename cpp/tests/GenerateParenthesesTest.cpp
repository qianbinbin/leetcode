#include "GenerateParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GenerateParentheses, Solution22_1) {
  const int N = 3;
  const std::vector<std::string> Expected{
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
  };
  EXPECT_EQ(Expected, Solution22_1().generateParenthesis(N));
}