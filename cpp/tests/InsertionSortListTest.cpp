#include "InsertionSortList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(InsertionSortList, Solution147_1) {
  auto Head1 = newLinkedList({4, 2, 1, 3});
  const auto Expected1 = newLinkedList({1, 2, 3, 4});
  Head1 = Solution147_1().insertionSortList(Head1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({-1, 5, 3, 4, 0});
  const auto Expected2 = newLinkedList({-1, 0, 3, 4, 5});
  Head2 = Solution147_1().insertionSortList(Head2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}