#include "LetterCombinationsOfAPhoneNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LetterCombinationsOfAPhoneNumber, Solution17_1) {
  auto S17_1 = Solution17_1();

  std::string Digits1 = "23";
  std::vector<std::string> const Expected1{"ad", "ae", "af", "bd", "be",
                                           "bf", "cd", "ce", "cf"};
  EXPECT_EQ(Expected1, S17_1.letterCombinations(Digits1));

  std::string Digits2;
  std::vector<std::string> const Expected2;
  EXPECT_EQ(Expected2, S17_1.letterCombinations(Digits2));

  std::string Digits3 = "2";
  std::vector<std::string> const Expected3{"a", "b", "c"};
  EXPECT_EQ(Expected3, S17_1.letterCombinations(Digits3));
}