#include "ConvertSortedListToBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConvertSortedListToBinarySearchTree, Solution109_1) {
  const auto Head = newLinkedList({-10, -3, 0, 5, 9});
  const auto Expected = newTree({0, -3, 9, -10, NTNode, 5}),
      Actual = Solution109_1().sortedListToBST(Head);
  EXPECT_EQ(*Expected, *Actual);
  deleteLinkedList(Head);
  deleteTree(Expected);
  deleteTree(Actual);
}