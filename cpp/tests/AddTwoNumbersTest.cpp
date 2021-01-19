#include "AddTwoNumbers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(AddTwoNumbers, Solution2_1) {
  auto S2_1 = Solution2_1();

  const auto L11 = newLinkedList({2, 4, 3});
  const auto L12 = newLinkedList({5, 6, 4});
  const auto Expected1 = newLinkedList({7, 0, 8});
  const auto Actual1 = S2_1.addTwoNumbers(L11, L12);
  EXPECT_EQ(*Expected1, *Actual1);
  deleteLinkedList(L11);
  deleteLinkedList(L12);
  deleteLinkedList(Expected1);
  deleteLinkedList(Actual1);

  const auto L21 = newLinkedList({0});
  const auto L22 = newLinkedList({0});
  const auto Expected2 = newLinkedList({0});
  const auto Actual2 = S2_1.addTwoNumbers(L21, L22);
  EXPECT_EQ(*Expected2, *Actual2);
  deleteLinkedList(L21);
  deleteLinkedList(L22);
  deleteLinkedList(Expected2);
  deleteLinkedList(Actual2);

  const auto L31 = newLinkedList({9, 9, 9, 9, 9, 9, 9});
  const auto L32 = newLinkedList({9, 9, 9, 9});
  const auto Expected3 = newLinkedList({8, 9, 9, 9, 0, 0, 0, 1});
  const auto Actual3 = S2_1.addTwoNumbers(L31, L32);
  EXPECT_EQ(*Expected3, *Actual3);
  deleteLinkedList(L31);
  deleteLinkedList(L32);
  deleteLinkedList(Expected3);
  deleteLinkedList(Actual3);
}