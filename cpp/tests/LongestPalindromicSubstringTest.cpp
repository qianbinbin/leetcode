#include "LongestPalindromicSubstring.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestPalindromicSubstring, Solution5_1) {
  auto S5_1 = Solution5_1();

  EXPECT_EQ("bab", S5_1.longestPalindrome("babad"));
  EXPECT_EQ("bb", S5_1.longestPalindrome("cbbd"));
  EXPECT_EQ("a", S5_1.longestPalindrome("a"));
  EXPECT_EQ("a", S5_1.longestPalindrome("ac"));
}