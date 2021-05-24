#include "PowXN.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(PowXN, Solution50_1) {
  auto S50_1 = Solution50_1();

  EXPECT_DOUBLE_EQ(1024.00000, S50_1.myPow(2.00000, 10));
  EXPECT_DOUBLE_EQ(9.26100, S50_1.myPow(2.10000, 3));
  EXPECT_DOUBLE_EQ(0.25000, S50_1.myPow(2.00000, -2));
}
