#include "RecoverBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RecoverBinarySearchTree, Solution99_1) {
  const auto Root1 = newTree({1, 3, NTNode, NTNode, 2});
  const auto Expected1 = newTree({3, 1, NTNode, NTNode, 2});
  Solution99_1().recoverTree(Root1);
  EXPECT_EQ(*Expected1, *Root1);
  deleteTree(Root1);
  deleteTree(Expected1);

  const auto Root2 = newTree({3, 1, 4, NTNode, NTNode, 2});
  const auto Expected2 = newTree({2, 1, 4, NTNode, NTNode, 3});
  Solution99_1().recoverTree(Root2);
  EXPECT_EQ(*Expected2, *Root2);
  deleteTree(Root2);
  deleteTree(Expected2);
}