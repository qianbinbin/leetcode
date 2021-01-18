#include "BalancedBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BalancedBinaryTree, Solution110_1) {
  const auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  EXPECT_TRUE(Solution110_1().isBalanced(Root1));
  deleteTree(Root1);

  const auto Root2 = newTree({1, 2, 2, 3, 3, NTNode, NTNode, 4, 4});
  EXPECT_FALSE(Solution110_1().isBalanced(Root2));
  deleteTree(Root2);
}