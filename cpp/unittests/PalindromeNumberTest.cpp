#include "PalindromeNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromeNumber, Solution9_1) {
  EXPECT_TRUE(Solution9_1().isPalindrome(121));
  EXPECT_FALSE(Solution9_1().isPalindrome(-121));
  EXPECT_FALSE(Solution9_1().isPalindrome(10));
}