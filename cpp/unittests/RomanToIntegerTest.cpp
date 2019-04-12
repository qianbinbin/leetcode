#include "RomanToInteger.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RomanToInteger, Solution13_1) {
  EXPECT_EQ(3, Solution13_1().romanToInt("III"));
  EXPECT_EQ(4, Solution13_1().romanToInt("IV"));
  EXPECT_EQ(9, Solution13_1().romanToInt("IX"));
  EXPECT_EQ(58, Solution13_1().romanToInt("LVIII"));
  EXPECT_EQ(1994, Solution13_1().romanToInt("MCMXCIV"));
}