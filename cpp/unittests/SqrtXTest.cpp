#include "SqrtX.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SqrtX, Solution69_1) {
  EXPECT_EQ(2, Solution69_1().mySqrt(4));
  EXPECT_EQ(2, Solution69_1().mySqrt(8));
}