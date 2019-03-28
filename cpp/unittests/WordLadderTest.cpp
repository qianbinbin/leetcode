#include "WordLadder.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordLadder, Solution127_1) {
  const std::string BeginWord1 = "hit", EndWord1 = "cog";
  std::vector<std::string> WordList1{
      "hot", "dot", "dog", "lot", "log", "cog"
  };
  const int Expected1 = 5;
  EXPECT_EQ(Expected1,
            Solution127_1().ladderLength(BeginWord1, EndWord1, WordList1));

  const std::string BeginWord2 = "hit", EndWord2 = "cog";
  std::vector<std::string> WordList2{
      "hot", "dot", "dog", "lot", "log"
  };
  const int Expected2 = 0;
  EXPECT_EQ(Expected2,
            Solution127_1().ladderLength(BeginWord2, EndWord2, WordList2));
}