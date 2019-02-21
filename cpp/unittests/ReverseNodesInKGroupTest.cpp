#include "ReverseNodesInKGroup.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseNodesInKGroup, Solution25_1) {
  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  const int K1 = 2;
  const auto Expected1 = newLinkedList({2, 1, 4, 3, 5});
  Head1 = Solution25_1().reverseKGroup(Head1, K1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1, 2, 3, 4, 5});
  const int K2 = 3;
  const auto Expected2 = newLinkedList({3, 2, 1, 4, 5});
  Head2 = Solution25_1().reverseKGroup(Head2, K2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}