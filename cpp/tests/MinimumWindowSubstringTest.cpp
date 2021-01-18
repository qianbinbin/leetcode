#include "MinimumWindowSubstring.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinimumWindowSubstring, Solution76_1) {
  const std::string S = "ADOBECODEBANC", T = "ABC", Expected = "BANC";
  EXPECT_EQ(Expected, Solution76_1().minWindow(S, T));
}