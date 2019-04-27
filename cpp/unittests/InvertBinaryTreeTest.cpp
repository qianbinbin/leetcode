#include "InvertBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InvertBinaryTree, Solution226_1) {
  const auto Root = newTree({4, 2, 7, 1, 3, 6, 9}),
             Expected = newTree({4, 7, 2, 9, 6, 3, 1});
  EXPECT_EQ(*Expected, *Solution226_1().invertTree(Root));
  deleteTree(Root);
  deleteTree(Expected);
}