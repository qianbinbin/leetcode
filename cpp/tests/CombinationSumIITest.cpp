#include "CombinationSumII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CombinationSumII, Solution40_1) {
  std::vector<int> Candidates1{10, 1, 2, 7, 6, 1, 5};
  const int Target1 = 8;
  const std::vector<std::vector<int>> Expected1{
      {1, 1, 6},
      {1, 2, 5},
      {1, 7},
      {2, 6}
  };
  EXPECT_EQ(Expected1, Solution40_1().combinationSum2(Candidates1, Target1));

  std::vector<int> Candidates2{2, 5, 2, 1, 2};
  const int Target2 = 5;
  const std::vector<std::vector<int>> Expected2{
      {1, 2, 2},
      {5},
  };
  EXPECT_EQ(Expected2, Solution40_1().combinationSum2(Candidates2, Target2));
}