#include "BinaryTreeMaximumPathSum.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeMaximumPathSum, Solution124_1) {
  auto S124_1 = Solution124_1();

  auto Root1 = newTree({1, 2, 3});
  int const Expected1 = 6;
  EXPECT_EQ(Expected1, S124_1.maxPathSum(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({-10, 9, 20, NTNode, NTNode, 15, 7});
  int const Expected2 = 42;
  EXPECT_EQ(Expected2, S124_1.maxPathSum(Root2));
  deleteTree(Root2);
}