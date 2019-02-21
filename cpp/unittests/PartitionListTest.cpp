#include "PartitionList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PartitionList, Solution86_1) {
  auto Head = newLinkedList({1, 4, 3, 2, 5, 2});
  const int X = 3;
  const auto Expected = newLinkedList({1, 2, 2, 4, 3, 5});
  Head = Solution86_1().partition(Head, X);
  EXPECT_EQ(*Expected, *Head);
  deleteLinkedList(Head);
  deleteLinkedList(Expected);
}