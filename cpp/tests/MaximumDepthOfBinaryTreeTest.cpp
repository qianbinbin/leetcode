#include "MaximumDepthOfBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MaximumDepthOfBinaryTree, Solution104_1) {
  const auto Root = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  const int Expected = 3;
  EXPECT_EQ(Expected, Solution104_1().maxDepth(Root));
  deleteTree(Root);
}