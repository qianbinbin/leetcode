#include "LetterCombinationsOfAPhoneNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LetterCombinationsOfAPhoneNumber, Solution17_1) {
  std::string Digits = "23";
  const std::vector<std::string> Expected{
      "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
  };
  EXPECT_EQ(Expected, Solution17_1().letterCombinations(Digits));
}