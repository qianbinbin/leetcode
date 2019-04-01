#include "LongestPalindromicSubstring.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestPalindromicSubstring, Solution5_1) {
  EXPECT_EQ("aba", Solution5_1().longestPalindrome("babad"));
  EXPECT_EQ("bb", Solution5_1().longestPalindrome("cbbd"));
}