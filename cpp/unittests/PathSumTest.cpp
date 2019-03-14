#include "PathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PathSum, Solution112_1) {
  const auto Root =
      newTree({5, 4, 8, 11, NTNode, 13, 4, 7, 2, NTNode, NTNode, NTNode, 1});
  const int Sum = 22;
  EXPECT_TRUE(Solution112_1().hasPathSum(Root, Sum));
  deleteTree(Root);
}