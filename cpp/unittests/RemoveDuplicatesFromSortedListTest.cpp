#include "RemoveDuplicatesFromSortedList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveDuplicatesFromSortedList, Solution83_1) {
  auto Head1 = newLinkedList({1, 1, 2});
  const auto Expected1 = newLinkedList({1, 2});
  Head1 = Solution83_1().deleteDuplicates(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1, 1, 2, 3, 3});
  const auto Expected2 = newLinkedList({1, 2, 3});
  Head2 = Solution83_1().deleteDuplicates(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}