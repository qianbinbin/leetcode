#include "ReverseLinkedListII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseLinkedListII, Solution92_1) {
  auto Head = newLinkedList({1, 2, 3, 4, 5});
  const int M = 2, N = 4;
  const auto Expected = newLinkedList({1, 4, 3, 2, 5});
  Head = Solution92_1().reverseBetween(Head, M, N);
  EXPECT_EQ(*Expected, *Head);
  deleteLinkedList(Head);
  deleteLinkedList(Expected);
}