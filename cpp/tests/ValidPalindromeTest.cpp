#include "ValidPalindrome.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ValidPalindrome, Solution125_1) {
  auto S125_1 = Solution125_1();

  EXPECT_TRUE(S125_1.isPalindrome("A man, a plan, a canal: Panama"));
  EXPECT_FALSE(S125_1.isPalindrome("race a car"));
  EXPECT_TRUE(S125_1.isPalindrome(" "));
}