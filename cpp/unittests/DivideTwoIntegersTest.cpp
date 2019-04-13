#include "DivideTwoIntegers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(DivideTwoIntegers, Solution29_1) {
  EXPECT_EQ(3, Solution29_1().divide(10, 3));
  EXPECT_EQ(-2, Solution29_1().divide(7, -3));
}