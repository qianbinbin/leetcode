#include <gtest/gtest.h>

extern "C" {
#include "roman_to_integer.h"
}

TEST(roman_to_integer_test, romanToInt_13_1) {
    EXPECT_EQ(3, romanToInt_13_1("III"));
    EXPECT_EQ(4, romanToInt_13_1("IV"));
    EXPECT_EQ(9, romanToInt_13_1("IX"));
    EXPECT_EQ(58, romanToInt_13_1("LVIII"));
    EXPECT_EQ(1994, romanToInt_13_1("MCMXCIV"));
}
