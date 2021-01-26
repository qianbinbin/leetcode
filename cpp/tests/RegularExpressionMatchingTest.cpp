#include "RegularExpressionMatching.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RegularExpressionMatching, Solution10_1) {
  auto S10_1 = Solution10_1();

  EXPECT_FALSE(S10_1.isMatch("aa", "a"));
  EXPECT_TRUE(S10_1.isMatch("aa", "a*"));
  EXPECT_TRUE(S10_1.isMatch("aa", ".*"));
  EXPECT_TRUE(S10_1.isMatch("aab", "c*a*b"));
  EXPECT_FALSE(S10_1.isMatch("mississippi", "mis*is*p*."));
}

TEST(RegularExpressionMatching, Solution10_2) {
  auto S10_2 = Solution10_2();

  EXPECT_FALSE(S10_2.isMatch("aa", "a"));
  EXPECT_TRUE(S10_2.isMatch("aa", "a*"));
  EXPECT_TRUE(S10_2.isMatch("aa", ".*"));
  EXPECT_TRUE(S10_2.isMatch("aab", "c*a*b"));
  EXPECT_FALSE(S10_2.isMatch("mississippi", "mis*is*p*."));
}
