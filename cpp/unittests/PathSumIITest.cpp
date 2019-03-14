#include "PathSumII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PathSumII, Solution113_1) {
  const auto
      Root = newTree({5, 4, 8, 11, NTNode, 13, 4, 7, 2, NTNode, NTNode, 5, 1});
  const int Sum = 22;
  const std::vector<std::vector<int>> Expected{
      {5, 4, 11, 2},
      {5, 8, 4, 5}
  };
  EXPECT_EQ(Expected, Solution113_1().pathSum(Root, Sum));
  deleteTree(Root);
}