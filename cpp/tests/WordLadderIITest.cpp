#include "WordLadderII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordLadderII, Solution126_1) {
  const std::string BeginWord1 = "hit", EndWord1 = "cog";
  std::vector<std::string> WordList1{
      "hot", "dot", "dog", "lot", "log", "cog"
  };
  const std::vector<std::vector<std::string>> Expected1{
      {"hit", "hot", "dot", "dog", "cog"},
      {"hit", "hot", "lot", "log", "cog"}
  };
  EXPECT_EQ(Expected1,
            Solution126_1().findLadders(BeginWord1, EndWord1, WordList1));

  const std::string BeginWord2 = "hit", EndWord2 = "cog";
  std::vector<std::string> WordList2{
      "hot", "dot", "dog", "lot", "log"
  };
  const std::vector<std::vector<std::string>> Expected2;
  EXPECT_EQ(Expected2,
            Solution126_1().findLadders(BeginWord2, EndWord2, WordList2));
}