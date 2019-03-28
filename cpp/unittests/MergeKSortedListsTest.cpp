#include "MergeKSortedLists.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeKSortedLists, Solution23_1) {
  std::vector<ListNode *> Lists{
      newLinkedList({1, 4, 5}),
      newLinkedList({1, 3, 4}),
      newLinkedList({2, 6})
  };
  const auto Expected = newLinkedList({1, 1, 2, 3, 4, 4, 5, 6}),
      Actual = Solution23_1().mergeKLists(Lists);
  EXPECT_EQ(*Expected, *Actual);
  deleteLinkedList(Expected);
  deleteLinkedList(Actual);
}