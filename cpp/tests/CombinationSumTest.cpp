#include "CombinationSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(CombinationSum, Solution39_1) {
  auto S39_1 = Solution39_1();

  std::vector<int> Candidates1{2, 3, 6, 7};
  int const Target1 = 7;
  std::vector<std::vector<int>> const Expected1{{2, 2, 3}, {7}};
  EXPECT_EQ(Expected1, S39_1.combinationSum(Candidates1, Target1));

  std::vector<int> Candidates2{2, 3, 5};
  int const Target2 = 8;
  std::vector<std::vector<int>> const Expected2{
      {2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
  EXPECT_EQ(Expected2, S39_1.combinationSum(Candidates2, Target2));

  std::vector<int> Candidates3{2};
  int const Target3 = 1;
  std::vector<std::vector<int>> const Expected3;
  EXPECT_EQ(Expected3, S39_1.combinationSum(Candidates3, Target3));

  std::vector<int> Candidates4{1};
  int const Target4 = 1;
  std::vector<std::vector<int>> const Expected4{{1}};
  EXPECT_EQ(Expected4, S39_1.combinationSum(Candidates4, Target4));

  std::vector<int> Candidates5{1};
  int const Target5 = 2;
  std::vector<std::vector<int>> const Expected5{{1, 1}};
  EXPECT_EQ(Expected5, S39_1.combinationSum(Candidates5, Target5));
}