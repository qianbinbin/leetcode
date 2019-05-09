#include "PerfectSquares.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PerfectSquares, Solution279_1) {
  EXPECT_EQ(3, Solution279_1().numSquares(12));
  EXPECT_EQ(2, Solution279_1().numSquares(13));
}

TEST(PerfectSquares, Solution279_2) {
  EXPECT_EQ(3, Solution279_2().numSquares(12));
  EXPECT_EQ(2, Solution279_2().numSquares(13));
}

TEST(PerfectSquares, Solution279_3) {
  EXPECT_EQ(3, Solution279_3().numSquares(12));
  EXPECT_EQ(2, Solution279_3().numSquares(13));
}
