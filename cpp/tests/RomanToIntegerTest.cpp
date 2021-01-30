#include "RomanToInteger.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RomanToInteger, Solution13_1) {
  auto S13_1 = Solution13_1();

  EXPECT_EQ(3, S13_1.romanToInt("III"));
  EXPECT_EQ(4, S13_1.romanToInt("IV"));
  EXPECT_EQ(9, S13_1.romanToInt("IX"));
  EXPECT_EQ(58, S13_1.romanToInt("LVIII"));
  EXPECT_EQ(1994, S13_1.romanToInt("MCMXCIV"));
}