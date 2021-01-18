#include "IntersectionOfTwoLinkedLists.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(IntersectionOfTwoLinkedLists, Solution160_1) {
  const auto HeadA1 = newLinkedList({4, 1, 8, 4, 5}),
             HeadB1 = newLinkedList({5, 0, 1});
  const auto Expected1 = HeadA1->next->next;
  HeadB1->next->next->next = Expected1;
  EXPECT_EQ(Expected1, Solution160_1().getIntersectionNode(HeadA1, HeadB1));
  HeadB1->next->next->next = nullptr;
  deleteLinkedList(HeadA1);
  deleteLinkedList(HeadB1);

  const auto HeadA2 = newLinkedList({0, 9, 1, 2, 4}),
             HeadB2 = newLinkedList({3, 2, 4});
  const auto Expected2 = HeadA2->next->next->next;
  HeadB2->next->next = Expected2;
  EXPECT_EQ(Expected2, Solution160_1().getIntersectionNode(HeadA2, HeadB2));
  HeadB2->next->next = nullptr;
  deleteLinkedList(HeadA2);
  deleteLinkedList(HeadB2);

  const auto HeadA3 = newLinkedList({2, 6, 4}), HeadB3 = newLinkedList({1, 5});
  EXPECT_EQ(nullptr, Solution160_1().getIntersectionNode(HeadA3, HeadB3));
  deleteLinkedList(HeadA3);
  deleteLinkedList(HeadB3);
}