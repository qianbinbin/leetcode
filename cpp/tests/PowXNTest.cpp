#include "PowXN.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PowXN, Solution50_1) {
  EXPECT_DOUBLE_EQ(1024.00000, Solution50_1().myPow(2.00000, 10));
  EXPECT_DOUBLE_EQ(9.26100, Solution50_1().myPow(2.10000, 3));
  EXPECT_DOUBLE_EQ(0.25000, Solution50_1().myPow(2.00000, -2));
}

TEST(PowXN, Solution50_2) {
  EXPECT_DOUBLE_EQ(1024.00000, Solution50_2().myPow(2.00000, 10));
  EXPECT_DOUBLE_EQ(9.26100, Solution50_2().myPow(2.10000, 3));
  EXPECT_DOUBLE_EQ(0.25000, Solution50_2().myPow(2.00000, -2));
}
