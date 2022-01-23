#include "MinimumWindowSubstring.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumWindowSubstring, Solution76_1) {
  auto S76_1 = Solution76_1();

  EXPECT_EQ("BANC", S76_1.minWindow("ADOBECODEBANC", "ABC"));
  EXPECT_EQ("a", S76_1.minWindow("a", "a"));
  EXPECT_EQ("", S76_1.minWindow("a", "aa"));
}