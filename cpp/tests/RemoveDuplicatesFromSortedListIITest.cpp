#include "RemoveDuplicatesFromSortedListII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedListII, Solution82_1) {
  auto Head1 = newLinkedList({1, 2, 3, 3, 4, 4, 5});
  const auto Expected1 = newLinkedList({1, 2, 5});
  Head1 = Solution82_1().deleteDuplicates(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1, 1, 1, 2, 3});
  const auto Expected2 = newLinkedList({2, 3});
  Head2 = Solution82_1().deleteDuplicates(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}