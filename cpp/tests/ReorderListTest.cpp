#include "ReorderList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReorderList, Solution143_1) {
  auto S143_1 = Solution143_1();

  auto Head1 = newLinkedList({1, 2, 3, 4});
  auto Expected1 = newLinkedList({1, 4, 2, 3});
  S143_1.reorderList(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1, 2, 3, 4, 5});
  auto Expected2 = newLinkedList({1, 5, 2, 4, 3});
  S143_1.reorderList(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}