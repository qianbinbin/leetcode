#include "RotateList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RotateList, Solution61_1) {
  auto S61_1 = Solution61_1();

  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  int const K1 = 2;
  auto Expected1 = newLinkedList({4, 5, 1, 2, 3});
  Head1 = S61_1.rotateRight(Head1, K1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({0, 1, 2});
  int const K2 = 4;
  auto Expected2 = newLinkedList({2, 0, 1});
  Head2 = S61_1.rotateRight(Head2, K2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}