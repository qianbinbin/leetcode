#include "ValidateBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidateBinarySearchTree, Solution98_1) {
  auto S98_1 = Solution98_1();

  auto Root1 = newTree({2, 1, 3});
  EXPECT_TRUE(S98_1.isValidBST(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({5, 1, 4, NTNode, NTNode, 3, 6});
  EXPECT_FALSE(Solution98_1().isValidBST(Root2));
  deleteTree(Root2);
}

TEST(ValidateBinarySearchTree, Solution98_2) {
  auto S98_2 = Solution98_2();

  auto Root1 = newTree({2, 1, 3});
  EXPECT_TRUE(S98_2.isValidBST(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({5, 1, 4, NTNode, NTNode, 3, 6});
  EXPECT_FALSE(S98_2.isValidBST(Root2));
  deleteTree(Root2);
}

TEST(ValidateBinarySearchTree, Solution98_3) {
  auto S98_3 = Solution98_3();

  auto Root1 = newTree({2, 1, 3});
  EXPECT_TRUE(S98_3.isValidBST(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({5, 1, 4, NTNode, NTNode, 3, 6});
  EXPECT_FALSE(S98_3.isValidBST(Root2));
  deleteTree(Root2);
}
