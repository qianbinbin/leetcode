#include "WordLadder.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WordLadder, Solution127_1) {
  auto S127_1 = Solution127_1();

  std::string BeginWord1 = "hit", EndWord1 = "cog";
  std::vector<std::string> WordList1{"hot", "dot", "dog", "lot", "log", "cog"};
  int const Expected1 = 5;
  EXPECT_EQ(Expected1, S127_1.ladderLength(BeginWord1, EndWord1, WordList1));

  std::string BeginWord2 = "hit", EndWord2 = "cog";
  std::vector<std::string> WordList2{"hot", "dot", "dog", "lot", "log"};
  int const Expected2 = 0;
  EXPECT_EQ(Expected2, S127_1.ladderLength(BeginWord2, EndWord2, WordList2));
}