#include "MergeTwoSortedLists.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MergeTwoSortedLists, Solution21_1) {
  auto S21_1 = Solution21_1();

  auto Head11 = newLinkedList({1, 2, 4}), Head12 = newLinkedList({1, 3, 4});
  auto Expected1 = newLinkedList({1, 1, 2, 3, 4, 4});
  auto Actual1 = S21_1.mergeTwoLists(Head11, Head12);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  EXPECT_EQ(nullptr, S21_1.mergeTwoLists(nullptr, nullptr));

  auto Head31 = newLinkedList({}), Head32 = newLinkedList({0});
  auto Expected3 = newLinkedList({0});
  auto Actual3 = S21_1.mergeTwoLists(Head31, Head32);
  EXPECT_EQ(*Expected3, *Actual3);
  deleteLinkedList(Expected3);
  deleteLinkedList(Actual3);
}