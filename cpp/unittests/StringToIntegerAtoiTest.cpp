#include "StringToIntegerAtoi.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(StringToIntegerAtoi, Solution8_1) {
  EXPECT_EQ(42, Solution8_1().myAtoi("42"));
  EXPECT_EQ(-42, Solution8_1().myAtoi("   -42"));
  EXPECT_EQ(4193, Solution8_1().myAtoi("4193 with words"));
  EXPECT_EQ(0, Solution8_1().myAtoi("words and 987"));
  EXPECT_EQ(INT32_MIN, Solution8_1().myAtoi("-91283472332"));
}