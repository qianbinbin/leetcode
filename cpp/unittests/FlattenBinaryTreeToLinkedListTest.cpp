#include "FlattenBinaryTreeToLinkedList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FlattenBinaryTreeToLinkedList, Solution114_1) {
  const auto Root = newTree({1, 2, 5, 3, 4, NTNode, 6}), Expected =
      newTree({1, NTNode, 2, NTNode, 3, NTNode, 4, NTNode, 5, NTNode, 6});
  Solution114_1().flatten(Root);
  EXPECT_EQ(*Expected, *Root);
  deleteTree(Root);
  deleteTree(Expected);
}