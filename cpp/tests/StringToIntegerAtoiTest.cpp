#include "StringToIntegerAtoi.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(StringToIntegerAtoi, Solution8_1) {
  auto S8_1 = Solution8_1();

  EXPECT_EQ(42, S8_1.myAtoi("42"));
  EXPECT_EQ(-42, S8_1.myAtoi("   -42"));
  EXPECT_EQ(4193, S8_1.myAtoi("4193 with words"));
  EXPECT_EQ(0, S8_1.myAtoi("words and 987"));
  EXPECT_EQ(INT_MIN, S8_1.myAtoi("-91283472332"));
}