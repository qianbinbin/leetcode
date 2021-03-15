#include "MergeKSortedLists.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeKSortedLists, Solution23_1) {
  auto S23_1 = Solution23_1();

  std::vector<ListNode *> Lists1{newLinkedList({1, 4, 5}),
                                 newLinkedList({1, 3, 4}),
                                 newLinkedList({2, 6})};
  auto Expected1 = newLinkedList({1, 1, 2, 3, 4, 4, 5, 6});
  auto Actual1 = S23_1.mergeKLists(Lists1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  std::vector<ListNode *> Lists2;
  auto Expected2 = newLinkedList({});
  auto Actual2 = S23_1.mergeKLists(Lists2);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteLinkedList(Expected2);
  deleteLinkedList(Actual2);

  std::vector<ListNode *> Lists3{newLinkedList({})};
  auto Expected3 = newLinkedList({});
  auto Actual3 = S23_1.mergeKLists(Lists3);
  EXPECT_EQ(*Expected3, *Actual3);
  deleteLinkedList(Expected3);
  deleteLinkedList(Actual3);
}

TEST(MergeKSortedLists, Solution23_2) {
  auto S23_2 = Solution23_2();

  std::vector<ListNode *> Lists1{newLinkedList({1, 4, 5}),
                                 newLinkedList({1, 3, 4}),
                                 newLinkedList({2, 6})};
  auto Expected1 = newLinkedList({1, 1, 2, 3, 4, 4, 5, 6});
  auto Actual1 = S23_2.mergeKLists(Lists1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  std::vector<ListNode *> Lists2;
  auto Actual2 = S23_2.mergeKLists(Lists2);
  EXPECT_EQ(nullptr, Actual2);

  std::vector<ListNode *> Lists3{nullptr};
  auto Actual3 = S23_2.mergeKLists(Lists3);
  EXPECT_EQ(nullptr, Actual3);
}
