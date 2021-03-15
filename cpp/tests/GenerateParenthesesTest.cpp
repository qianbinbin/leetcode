#include "GenerateParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GenerateParentheses, Solution22_1) {
  auto S22_1 = Solution22_1();

  int const N1 = 3;
  std::vector<std::string> const Expected1{"((()))", "(()())", "(())()",
                                           "()(())", "()()()"};
  EXPECT_EQ(Expected1, S22_1.generateParenthesis(N1));

  int const N2 = 1;
  std::vector<std::string> const Expected2{"()"};
  EXPECT_EQ(Expected2, S22_1.generateParenthesis(N2));
}