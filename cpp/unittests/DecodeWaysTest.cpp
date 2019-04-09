#include "DecodeWays.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(DecodeWays, Solution91_1) {
  EXPECT_EQ(2, Solution91_1().numDecodings("12"));
  EXPECT_EQ(3, Solution91_1().numDecodings("226"));
}
