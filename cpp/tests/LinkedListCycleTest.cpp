#include "LinkedListCycle.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LinkedListCycle, Solution141_1) {
  const auto Head1 = newLinkedList({3, 2, 0, -4}),
      Tail1 = Head1->next->next->next;
  Tail1->next = Head1->next;
  EXPECT_TRUE(Solution141_1().hasCycle(Head1));
  Tail1->next = nullptr;
  deleteLinkedList(Head1);

  const auto Head2 = newLinkedList({1, 2}),
      Tail2 = Head2->next;
  Tail2->next = Head2;
  EXPECT_TRUE(Solution141_1().hasCycle(Head2));
  Tail2->next = nullptr;
  deleteLinkedList(Head2);

  const auto Head3 = newLinkedList({1});
  EXPECT_FALSE(Solution141_1().hasCycle(Head3));
  deleteLinkedList(Head3);
}