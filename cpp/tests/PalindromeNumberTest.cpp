#include "PalindromeNumber.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PalindromeNumber, Solution9_1) {
  auto S9_1 = Solution9_1();

  EXPECT_TRUE(S9_1.isPalindrome(121));
  EXPECT_FALSE(S9_1.isPalindrome(-121));
  EXPECT_FALSE(S9_1.isPalindrome(10));
  EXPECT_FALSE(S9_1.isPalindrome(-101));
}
