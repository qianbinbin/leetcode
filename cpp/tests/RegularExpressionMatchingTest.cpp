#include "RegularExpressionMatching.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RegularExpressionMatching, Solution10_1) {
  EXPECT_FALSE(Solution10_1().isMatch("aa", "a"));
  EXPECT_TRUE(Solution10_1().isMatch("aa", "a*"));
  EXPECT_TRUE(Solution10_1().isMatch("aa", ".*"));
  EXPECT_TRUE(Solution10_1().isMatch("aab", "c*a*b"));
  EXPECT_FALSE(Solution10_1().isMatch("mississippi", "mis*is*p*."));
}