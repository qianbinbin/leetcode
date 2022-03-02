#include "WordLadderII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordLadderII, Solution126_1) {
  auto S126_1 = Solution126_1();

  std::string const BeginWord1 = "hit", EndWord1 = "cog";
  std::vector<std::string> WordList1{"hot", "dot", "dog", "lot", "log", "cog"};
  std::vector<std::vector<std::string>> const Expected1{
      {"hit", "hot", "dot", "dog", "cog"}, {"hit", "hot", "lot", "log", "cog"}};
  EXPECT_EQ(Expected1, S126_1.findLadders(BeginWord1, EndWord1, WordList1));

  std::string const BeginWord2 = "hit", EndWord2 = "cog";
  std::vector<std::string> WordList2{"hot", "dot", "dog", "lot", "log"};
  std::vector<std::vector<std::string>> const Expected2;
  EXPECT_EQ(Expected2, S126_1.findLadders(BeginWord2, EndWord2, WordList2));
}