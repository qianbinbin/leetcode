#include "BalancedBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(BalancedBinaryTree, Solution110_1) {
  auto S110_1 = Solution110_1();

  auto Root1 = newTree({3, 9, 20, NTNode, NTNode, 15, 7});
  EXPECT_TRUE(S110_1.isBalanced(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1, 2, 2, 3, 3, NTNode, NTNode, 4, 4});
  EXPECT_FALSE(S110_1.isBalanced(Root2));
  deleteTree(Root2);

  auto Root3 = newTree({});
  EXPECT_TRUE(S110_1.isBalanced(Root3));
  deleteTree(Root3);
}