#include "BinaryTreeLevelOrderTraversal.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeLevelOrderTraversal, Solution102_1) {
  const auto Root = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  const std::vector<std::vector<int>> Expected{
      {3},
      {9, 20},
      {15, 7}
  };
  EXPECT_EQ(Expected, Solution102_1().levelOrder(Root));
  deleteTree(Root);
}