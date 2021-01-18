#include "BinaryTreeLevelOrderTraversalII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BinaryTreeLevelOrderTraversalII, Solution107_1) {
  const auto Root = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  const std::vector<std::vector<int>> Expected{
      {15, 7},
      {9, 20},
      {3}
  };
  EXPECT_EQ(Expected, Solution107_1().levelOrderBottom(Root));
  deleteTree(Root);
}