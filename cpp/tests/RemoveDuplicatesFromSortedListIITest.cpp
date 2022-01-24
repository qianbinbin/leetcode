#include "RemoveDuplicatesFromSortedListII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedListII, Solution82_1) {
  auto S82_1 = Solution82_1();

  auto Head1 = newLinkedList({1, 2, 3, 3, 4, 4, 5});
  auto Expected1 = newLinkedList({1, 2, 5});
  Head1 = S82_1.deleteDuplicates(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1, 1, 1, 2, 3});
  auto Expected2 = newLinkedList({2, 3});
  Head2 = S82_1.deleteDuplicates(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}