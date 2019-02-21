#include "RotateList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RotateList, Solution61_1) {
  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  const int K1 = 2;
  const auto Expected1 = newLinkedList({4, 5, 1, 2, 3});
  Head1 = Solution61_1().rotateRight(Head1, K1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({0, 1, 2});
  const int K2 = 4;
  const auto Expected2 = newLinkedList({2, 0, 1});
  Head2 = Solution61_1().rotateRight(Head2, K2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}