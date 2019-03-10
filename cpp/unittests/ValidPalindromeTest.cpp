#include "ValidPalindrome.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidPalindrome, Solution125_1) {
  EXPECT_TRUE(Solution125_1().isPalindrome("A man, a plan, a canal: Panama"));
  EXPECT_FALSE(Solution125_1().isPalindrome("race a car"));
}