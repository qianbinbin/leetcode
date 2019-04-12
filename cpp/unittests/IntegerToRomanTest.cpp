#include "IntegerToRoman.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(IntegerToRoman, Solution12_1) {
  EXPECT_EQ("III", Solution12_1().intToRoman(3));
  EXPECT_EQ("IV", Solution12_1().intToRoman(4));
  EXPECT_EQ("IX", Solution12_1().intToRoman(9));
  EXPECT_EQ("LVIII", Solution12_1().intToRoman(58));
  EXPECT_EQ("MCMXCIV", Solution12_1().intToRoman(1994));
}