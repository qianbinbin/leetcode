#include "PalindromeLinkedList.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromeLinkedList, Solution234_1) {
  const auto Head1 = newLinkedList({1, 2});
  EXPECT_FALSE(Solution234_1().isPalindrome(Head1));
  deleteLinkedList(Head1);

  const auto Head2 = newLinkedList({1, 2, 2, 1});
  EXPECT_TRUE(Solution234_1().isPalindrome(Head2));
  deleteLinkedList(Head2);
}

TEST(PalindromeLinkedList, Solution234_2) {
  const auto Head1 = newLinkedList({1, 2});
  EXPECT_FALSE(Solution234_2().isPalindrome(Head1));
  deleteLinkedList(Head1);

  const auto Head2 = newLinkedList({1, 2, 2, 1});
  EXPECT_TRUE(Solution234_2().isPalindrome(Head2));
  deleteLinkedList(Head2);
}
