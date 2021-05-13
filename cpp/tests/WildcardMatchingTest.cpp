#include "WildcardMatching.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(WildcardMatching, Solution44_1) {
  auto S44_1 = Solution44_1();

  EXPECT_FALSE(S44_1.isMatch("aa", "a"));
  EXPECT_TRUE(S44_1.isMatch("aa", "*"));
  EXPECT_FALSE(S44_1.isMatch("cb", "?a"));
  EXPECT_TRUE(S44_1.isMatch("adceb", "*a*b"));
  EXPECT_FALSE(S44_1.isMatch("acdcb", "a*c?b"));
}

TEST(WildcardMatching, Solution44_2) {
  auto S44_2 = Solution44_2();

  EXPECT_FALSE(S44_2.isMatch("aa", "a"));
  EXPECT_TRUE(S44_2.isMatch("aa", "*"));
  EXPECT_FALSE(S44_2.isMatch("cb", "?a"));
  EXPECT_TRUE(S44_2.isMatch("adceb", "*a*b"));
  EXPECT_FALSE(S44_2.isMatch("acdcb", "a*c?b"));
}
