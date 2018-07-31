#include <gtest/gtest.h>

extern "C" {
#include "roman_to_integer.h"
}

TEST(roman_to_integer_test, romanToInt_13_1) {
    EXPECT_EQ(romanToInt_13_1("III"), 3);
    EXPECT_EQ(romanToInt_13_1("IV"), 4);
    EXPECT_EQ(romanToInt_13_1("IX"), 9);
    EXPECT_EQ(romanToInt_13_1("LVIII"), 58);
    EXPECT_EQ(romanToInt_13_1("MCMXCIV"), 1994);
}
