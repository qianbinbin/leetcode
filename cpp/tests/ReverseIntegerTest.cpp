#include "ReverseInteger.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ReverseInteger, Solution7_1) {
  EXPECT_EQ(321, Solution7_1().reverse(123));
  EXPECT_EQ(-321, Solution7_1().reverse(-123));
  EXPECT_EQ(21, Solution7_1().reverse(120));
}

TEST(ReverseInteger, Solution7_2) {
  EXPECT_EQ(321, Solution7_2().reverse(123));
  EXPECT_EQ(-321, Solution7_2().reverse(-123));
  EXPECT_EQ(21, Solution7_2().reverse(120));
}
