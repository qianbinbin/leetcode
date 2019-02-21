#include "SwapNodesInPairs.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SwapNodesInPairs, Solution24_1) {
  auto Head = newLinkedList({1, 2, 3, 4});
  const auto Expected = newLinkedList({2, 1, 4, 3});
  Head = Solution24_1().swapPairs(Head);
  EXPECT_EQ(*Expected, *Head);
  deleteLinkedList(Head);
  deleteLinkedList(Expected);
}