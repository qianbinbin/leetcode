#include "IntegerToRoman.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(IntegerToRoman, Solution12_1) {
  auto S12_1 = Solution12_1();

  EXPECT_EQ("III", S12_1.intToRoman(3));
  EXPECT_EQ("IV", S12_1.intToRoman(4));
  EXPECT_EQ("IX", S12_1.intToRoman(9));
  EXPECT_EQ("LVIII", S12_1.intToRoman(58));
  EXPECT_EQ("MCMXCIV", S12_1.intToRoman(1994));
}