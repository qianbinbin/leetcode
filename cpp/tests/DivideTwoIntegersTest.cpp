#include "DivideTwoIntegers.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(DivideTwoIntegers, Solution29_1) {
  auto S29_1 = Solution29_1();

  EXPECT_EQ(3, S29_1.divide(10, 3));
  EXPECT_EQ(-2, S29_1.divide(7, -3));
  EXPECT_EQ(0, S29_1.divide(0, 1));
  EXPECT_EQ(1, S29_1.divide(1, 1));
}