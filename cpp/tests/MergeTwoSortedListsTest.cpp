#include "MergeTwoSortedLists.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeTwoSortedLists, Solution21_1) {
  const auto Head1 = newLinkedList({1, 2, 4}), Head2 = newLinkedList({1, 3, 4});
  const auto Expected = newLinkedList({1, 1, 2, 3, 4, 4}),
      Actual = Solution21_1().mergeTwoLists(Head1, Head2);
  EXPECT_EQ(*Expected, *Actual);
  deleteLinkedList(Expected);
  deleteLinkedList(Actual);
}