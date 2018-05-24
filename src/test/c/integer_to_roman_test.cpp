#include <gtest/gtest.h>

extern "C" {
#include "integer_to_roman.h"
}

TEST(integer_to_roman_test, intToRoman_12_1) {
    char *ret = intToRoman_12_1(3);
    EXPECT_STREQ(ret, "III");
    free(ret);
    ret = intToRoman_12_1(4);
    EXPECT_STREQ(ret, "IV");
    free(ret);
    ret = intToRoman_12_1(9);
    EXPECT_STREQ(ret, "IX");
    free(ret);
    ret = intToRoman_12_1(58);
    EXPECT_STREQ(ret, "LVIII");
    free(ret);
    ret = intToRoman_12_1(1994);
    EXPECT_STREQ(ret, "MCMXCIV");
    free(ret);
}
