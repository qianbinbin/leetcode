#include "CombinationSumII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CombinationSumII, Solution40_1) {
  auto S40_1 = Solution40_1();

  std::vector<int> Candidates1{10, 1, 2, 7, 6, 1, 5};
  int const Target1 = 8;
  std::vector<std::vector<int>> const Expected1{
      {1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
  EXPECT_EQ(Expected1, S40_1.combinationSum2(Candidates1, Target1));

  std::vector<int> Candidates2{2, 5, 2, 1, 2};
  int const Target2 = 5;
  std::vector<std::vector<int>> const Expected2{
      {1, 2, 2},
      {5},
  };
  EXPECT_EQ(Expected2, S40_1.combinationSum2(Candidates2, Target2));
}