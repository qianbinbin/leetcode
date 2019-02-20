#include "AddTwoNumbers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(AddTwoNumbers, Solution2_1) {
  const auto Head1 = newLinkedList({2, 4, 3}), Head2 = newLinkedList({5, 6, 4});
  const auto Expected = newLinkedList({7, 0, 8}),
      Actual = Solution2_1().addTwoNumbers(Head1, Head2);
  EXPECT_EQ(*Expected, *Actual);
  deleteLinkedList(Head1);
  deleteLinkedList(Head2);
  deleteLinkedList(Expected);
  deleteLinkedList(Actual);
}