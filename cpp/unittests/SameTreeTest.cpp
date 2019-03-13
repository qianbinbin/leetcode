#include "SameTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SameTree, Solution100_1) {
  const auto Root1 = newTree({1, 2, 3});
  const auto Expected1 = newTree({1, 2, 3});
  EXPECT_TRUE(Solution100_1().isSameTree(Root1, Expected1));
  deleteTree(Root1);
  deleteTree(Expected1);

  const auto Root2 = newTree({1, 2});
  const auto Expected2 = newTree({1, NTNode, 2});
  EXPECT_FALSE(Solution100_1().isSameTree(Root2, Expected2));
  deleteTree(Root2);
  deleteTree(Expected2);

  const auto Root3 = newTree({1, 2, 1});
  const auto Expected3 = newTree({1, 1, 2});
  EXPECT_FALSE(Solution100_1().isSameTree(Root3, Expected3));
  deleteTree(Root3);
  deleteTree(Expected3);
}