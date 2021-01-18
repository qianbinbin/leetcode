#include "WordBreakII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordBreakII, Solution140_1) {
  const std::string S1 = "catsanddog";
  std::vector<std::string> WordDict1{"cat", "cats", "and", "sand", "dog"};
  const std::vector<std::string> Expected1{"cat sand dog", "cats and dog"};
  EXPECT_EQ(Expected1, Solution140_1().wordBreak(S1, WordDict1));

  const std::string S2 = "pineapplepenapple";
  std::vector<std::string> WordDict2{"apple", "pen", "applepen", "pine",
                                     "pineapple"};
  const std::vector<std::string> Expected2{
      "pine apple pen apple", "pine applepen apple", "pineapple pen apple"};
  EXPECT_EQ(Expected2, Solution140_1().wordBreak(S2, WordDict2));

  const std::string S3 = "catsandog";
  std::vector<std::string> WordDict3{"cats", "dog", "sand", "and", "cat"};
  const std::vector<std::string> Expected3;
  EXPECT_EQ(Expected3, Solution140_1().wordBreak(S3, WordDict3));
}