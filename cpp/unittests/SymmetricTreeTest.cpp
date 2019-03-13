#include "SymmetricTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SymmetricTree, Solution101_1) {
  const auto Root1 = newTree({1, 2, 2, 3, 4, 4, 3});
  EXPECT_TRUE(Solution101_1().isSymmetric(Root1));
  deleteTree(Root1);

  const auto Root2 = newTree({1, 2, 2, NTNode, 3, NTNode, 3});
  EXPECT_FALSE(Solution101_1().isSymmetric(Root2));
  deleteTree(Root2);
}
