#include "SwapNodesInPairs.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SwapNodesInPairs, Solution24_1) {
  auto S24_1 = Solution24_1();

  auto Head1 = newLinkedList({1, 2, 3, 4});
  auto Expected1 = newLinkedList({2, 1, 4, 3});
  auto Actual1 = S24_1.swapPairs(Head1);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  EXPECT_EQ(nullptr, S24_1.swapPairs(nullptr));

  auto Head3 = newLinkedList({1});
  auto Expected3 = newLinkedList({1});
  auto Actual3 = S24_1.swapPairs(Head3);
  EXPECT_EQ(*Expected3, *Actual3);
  deleteLinkedList(Expected3);
  deleteLinkedList(Actual3);
}