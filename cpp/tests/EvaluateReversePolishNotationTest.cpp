#include "EvaluateReversePolishNotation.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(EvaluateReversePolishNotation, Solution150_1) {
  auto S150_1 = Solution150_1();

  std::vector<std::string> Tokens1{"2", "1", "+", "3", "*"};
  int const Expected1 = 9;
  EXPECT_EQ(Expected1, S150_1.evalRPN(Tokens1));

  std::vector<std::string> Tokens2{"4", "13", "5", "/", "+"};
  int const Expected2 = 6;
  EXPECT_EQ(Expected2, S150_1.evalRPN(Tokens2));

  std::vector<std::string> Tokens3{"10", "6", "9",  "3", "+", "-11", "*",
                                   "/",  "*", "17", "+", "5", "+"};
  int const Expected3 = 22;
  EXPECT_EQ(Expected3, S150_1.evalRPN(Tokens3));
}