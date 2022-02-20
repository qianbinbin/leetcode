#include "ConvertSortedListToBinarySearchTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ConvertSortedListToBinarySearchTree, Solution109_1) {
  auto S109_1 = Solution109_1();

  auto Head1 = newLinkedList({-10, -3, 0, 5, 9});
  auto Expected1 = newTree({0, -3, 9, -10, NTNode, 5});
  auto Actual1 = S109_1.sortedListToBST(Head1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Head1);
  deleteTree(Expected1);
  deleteTree(Actual1);

  auto Head2 = newLinkedList({});
  auto Expected2 = newTree({});
  auto Actual2 = S109_1.sortedListToBST(Head2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteLinkedList(Head2);
  deleteTree(Expected2);
  deleteTree(Actual2);
}