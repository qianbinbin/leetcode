#include "CombinationSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CombinationSum, Solution39_1) {
  std::vector<int> Candidates1{2, 3, 6, 7};
  const int Target1 = 7;
  const std::vector<std::vector<int>> Expected1{{2, 2, 3}, {7}};
  EXPECT_EQ(Expected1, Solution39_1().combinationSum(Candidates1, Target1));

  std::vector<int> Candidates2{2, 3, 5};
  const int Target2 = 8;
  const std::vector<std::vector<int>> Expected2{
      {2, 2, 2, 2},
      {2, 3, 3},
      {3, 5}
  };
  EXPECT_EQ(Expected2, Solution39_1().combinationSum(Candidates2, Target2));
}