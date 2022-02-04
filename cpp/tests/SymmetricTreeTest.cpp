#include "SymmetricTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SymmetricTree, Solution101_1) {
  auto S101_1 = Solution101_1();

  auto Root1 = newTree({1, 2, 2, 3, 4, 4, 3});
  EXPECT_TRUE(S101_1.isSymmetric(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1, 2, 2, NTNode, 3, NTNode, 3});
  EXPECT_FALSE(S101_1.isSymmetric(Root2));
  deleteTree(Root2);
}

TEST(SymmetricTree, Solution101_2) {
  auto S101_2 = Solution101_2();

  auto Root1 = newTree({1, 2, 2, 3, 4, 4, 3});
  EXPECT_TRUE(S101_2.isSymmetric(Root1));
  deleteTree(Root1);

  auto Root2 = newTree({1, 2, 2, NTNode, 3, NTNode, 3});
  EXPECT_FALSE(S101_2.isSymmetric(Root2));
  deleteTree(Root2);
}
