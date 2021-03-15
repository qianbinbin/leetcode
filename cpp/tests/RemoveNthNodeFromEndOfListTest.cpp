#include "RemoveNthNodeFromEndOfList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RemoveNthNodeFromEndOfList, Solution19_1) {
  auto S19_1 = Solution19_1();

  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  int const N1 = 2;
  auto Expected1 = newLinkedList({1, 2, 3, 5});
  Head1 = S19_1.removeNthFromEnd(Head1, N1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({1});
  int const N2 = 1;
  auto Expected2 = newLinkedList({});
  Head2 = S19_1.removeNthFromEnd(Head2, N2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);

  auto Head3 = newLinkedList({1, 2});
  int const N3 = 1;
  auto Expected3 = newLinkedList({1});
  Head3 = S19_1.removeNthFromEnd(Head3, N3);
  EXPECT_EQ(*Expected3, *Head3);
  deleteLinkedList(Head3);
  deleteLinkedList(Expected3);
}