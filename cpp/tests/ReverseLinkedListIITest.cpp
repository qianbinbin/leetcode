#include "ReverseLinkedListII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseLinkedListII, Solution92_1) {
  auto S92_1 = Solution92_1();

  auto Head1 = newLinkedList({1, 2, 3, 4, 5});
  int const Left1 = 2, Right1 = 4;
  auto Expected1 = newLinkedList({1, 4, 3, 2, 5});
  Head1 = S92_1.reverseBetween(Head1, Left1, Right1);
  EXPECT_EQ(*Expected1, *Head1);
  deleteLinkedList(Head1);
  deleteLinkedList(Expected1);

  auto Head2 = newLinkedList({5});
  int const Left2 = 1, Right2 = 1;
  auto Expected2 = newLinkedList({5});
  Head2 = S92_1.reverseBetween(Head2, Left2, Right2);
  EXPECT_EQ(*Expected2, *Head2);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected2);
}