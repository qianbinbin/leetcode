#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeZigzagLevelOrderTraversal, Solution103_1) {
  const auto Root = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  const std::vector<std::vector<int>> Expected{
      {3},
      {20, 9},
      {15, 7}
  };
  EXPECT_EQ(Expected, Solution103_1().zigzagLevelOrder(Root));
  deleteTree(Root);
}