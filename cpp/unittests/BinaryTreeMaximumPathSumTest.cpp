#include "BinaryTreeMaximumPathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeMaximumPathSum, Solution124_1) {
  const auto Root1 = newTree({1, 2, 3});
  const int Expected1 = 6;
  EXPECT_EQ(Expected1, Solution124_1().maxPathSum(Root1));
  deleteTree(Root1);

  const auto Root2 = newTree({-10, 9, 20, NTNode, NTNode, 15, 7});
  const int Expected2 = 42;
  EXPECT_EQ(Expected2, Solution124_1().maxPathSum(Root2));
  deleteTree(Root2);
}