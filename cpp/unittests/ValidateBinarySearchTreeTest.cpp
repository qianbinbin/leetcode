#include "ValidateBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidateBinarySearchTree, Solution98_1) {
  const auto Root1 = newTree({2, 1, 3});
  EXPECT_TRUE(Solution98_1().isValidBST(Root1));
  deleteTree(Root1);

  const auto Root2 = newTree({5, 1, 4, NTNode, NTNode, 3, 6});
  EXPECT_FALSE(Solution98_1().isValidBST(Root2));
  deleteTree(Root2);
}