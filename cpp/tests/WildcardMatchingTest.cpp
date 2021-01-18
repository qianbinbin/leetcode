#include "WildcardMatching.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WildcardMatching, Solution44_1) {
  EXPECT_FALSE(Solution44_1().isMatch("aa", "a"));
  EXPECT_TRUE(Solution44_1().isMatch("aa", "*"));
  EXPECT_FALSE(Solution44_1().isMatch("cb", "?a"));
  EXPECT_TRUE(Solution44_1().isMatch("adceb", "*a*b"));
  EXPECT_FALSE(Solution44_1().isMatch("acdcb", "a*c?b"));
}

TEST(WildcardMatching, Solution44_2) {
  EXPECT_FALSE(Solution44_2().isMatch("aa", "a"));
  EXPECT_TRUE(Solution44_2().isMatch("aa", "*"));
  EXPECT_FALSE(Solution44_2().isMatch("cb", "?a"));
  EXPECT_TRUE(Solution44_2().isMatch("adceb", "*a*b"));
  EXPECT_FALSE(Solution44_2().isMatch("acdcb", "a*c?b"));
}
