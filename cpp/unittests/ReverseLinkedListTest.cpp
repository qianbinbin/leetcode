#include "ReverseLinkedList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseLinkedList, Solution206_1) {
  auto Head = newLinkedList({1, 2, 3, 4, 5});
  Head = Solution206_1().reverseList(Head);
  const auto Expected = newLinkedList({5, 4, 3, 2, 1});
  EXPECT_EQ(*Expected, *Head);
  deleteLinkedList(Head);
  deleteLinkedList(Expected);
}