#include "WordBreakII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordBreakII, Solution140_1) {
  auto S140_1 = Solution140_1();

  std::string const S1 = "catsanddog";
  std::vector<std::string> WordDict1{"cat", "cats", "and", "sand", "dog"};
  std::vector<std::string> const Expected1{"cat sand dog", "cats and dog"};
  EXPECT_EQ(Expected1, S140_1.wordBreak(S1, WordDict1));

  std::string const S2 = "pineapplepenapple";
  std::vector<std::string> WordDict2{"apple", "pen", "applepen", "pine",
                                     "pineapple"};
  std::vector<std::string> const Expected2{
      "pine apple pen apple", "pine applepen apple", "pineapple pen apple"};
  EXPECT_EQ(Expected2, S140_1.wordBreak(S2, WordDict2));

  std::string const S3 = "catsandog";
  std::vector<std::string> WordDict3{"cats", "dog", "sand", "and", "cat"};
  std::vector<std::string> const Expected3;
  EXPECT_EQ(Expected3, S140_1.wordBreak(S3, WordDict3));
}