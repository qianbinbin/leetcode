#include "DecodeWays.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(DecodeWays, Solution91_1) {
  auto S91_1 = Solution91_1();

  EXPECT_EQ(2, S91_1.numDecodings("12"));
  EXPECT_EQ(3, S91_1.numDecodings("226"));
  EXPECT_EQ(0, S91_1.numDecodings("06"));
}
