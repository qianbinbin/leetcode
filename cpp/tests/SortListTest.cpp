#include "SortList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SortList, Solution148_1) {
  auto S148_1 = Solution148_1();

  auto Head1 = newLinkedList({4, 2, 1, 3});
  auto Expected1 = newLinkedList({1, 2, 3, 4});
  Head1 = S148_1.sortList(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({-1, 5, 3, 4, 0});
  auto Expected2 = newLinkedList({-1, 0, 3, 4, 5});
  Head2 = S148_1.sortList(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);

  auto Head3 = newLinkedList({});
  auto Expected3 = newLinkedList({});
  Head3 = S148_1.sortList(Head3);
  EXPECT_EQ(*Expected3, *Head3);
  deleteLinkedList(Head3);
  deleteLinkedList(Expected3);
}