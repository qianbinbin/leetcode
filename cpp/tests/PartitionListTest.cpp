#include "PartitionList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PartitionList, Solution86_1) {
  auto S86_1 = Solution86_1();

  auto Head1 = newLinkedList({1, 4, 3, 2, 5, 2});
  int const X1 = 3;
  auto Expected1 = newLinkedList({1, 2, 2, 4, 3, 5});
  Head1 = S86_1.partition(Head1, X1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({2, 1});
  int const X2 = 2;
  auto Expected2 = newLinkedList({1, 2});
  Head2 = S86_1.partition(Head2, X2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}