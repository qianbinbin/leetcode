#include "LinkedListCycleII.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LinkedListCycleII, Solution142_1) {
  const auto Head1 = newLinkedList({3, 2, 0, -4}),
      Tail1 = Head1->next->next->next;
  Tail1->next = Head1->next;
  EXPECT_EQ(Tail1->next, Solution142_1().detectCycle(Head1));
  Tail1->next = nullptr;
  deleteLinkedList(Head1);

  const auto Head2 = newLinkedList({1, 2}),
      Tail2 = Head2->next;
  Tail2->next = Head2;
  EXPECT_EQ(Tail2->next, Solution142_1().detectCycle(Head2));
  Tail2->next = nullptr;
  deleteLinkedList(Head2);

  const auto Head3 = newLinkedList({1});
  EXPECT_EQ(nullptr, Solution142_1().detectCycle(Head3));
  deleteLinkedList(Head3);
}
