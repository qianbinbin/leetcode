#include "SqrtX.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SqrtX, Solution69_1) {
  EXPECT_EQ(2, Solution69_1().mySqrt(4));
  EXPECT_EQ(2, Solution69_1().mySqrt(8));
}

TEST(SqrtX, Solution69_2) {
  EXPECT_EQ(2, Solution69_2().mySqrt(4));
  EXPECT_EQ(2, Solution69_2().mySqrt(8));
}
