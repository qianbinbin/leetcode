#include "MinimumDepthOfBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumDepthOfBinaryTree, Solution111_1) {
  const auto Root = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  const int Expected = 2;
  EXPECT_EQ(Expected, Solution111_1().minDepth(Root));
  deleteTree(Root);
}