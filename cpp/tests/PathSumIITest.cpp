#include "PathSumII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PathSumII, Solution113_1) {
  auto S113_1 = Solution113_1();

  auto Root1 =
      newTree({5, 4, 8, 11, NTNode, 13, 4, 7, 2, NTNode, NTNode, 5, 1});
  int const TargetSum1 = 22;
  std::vector<std::vector<int>> const Expected1{{5, 4, 11, 2}, {5, 8, 4, 5}};
  EXPECT_EQ(Expected1, S113_1.pathSum(Root1, TargetSum1));
  deleteTree(Root1);

  auto Root2 = newTree({1, 2, 3});
  int const TargetSum2 = 5;
  std::vector<std::vector<int>> const Expected2;
  EXPECT_EQ(Expected2, S113_1.pathSum(Root2, TargetSum2));
  deleteTree(Root2);

  auto Root3 = newTree({1, 2});
  int const TargetSum3 = 0;
  std::vector<std::vector<int>> const Expected3;
  EXPECT_EQ(Expected3, S113_1.pathSum(Root3, TargetSum3));
  deleteTree(Root3);
}