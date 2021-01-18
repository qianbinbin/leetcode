#include "RemoveNthNodeFromEndOfList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveNthNodeFromEndOfList, Solution19_1) {
  auto Head = newLinkedList({1, 2, 3, 4, 5});
  const int N = 2;
  const auto Expected = newLinkedList({1, 2, 3, 5});
  Head = Solution19_1().removeNthFromEnd(Head, N);
  EXPECT_EQ(*Expected, *Head);
  deleteLinkedList(Head);
  deleteLinkedList(Expected);
}