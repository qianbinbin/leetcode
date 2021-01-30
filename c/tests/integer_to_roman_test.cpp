#include <gtest/gtest.h>

extern "C" {
#include "integer_to_roman.h"
}

TEST(integer_to_roman_test, intToRoman_12_1) {
    char *actual1 = intToRoman_12_1(3);
    EXPECT_STREQ("III", actual1);
    free(actual1);

    char *actual2 = intToRoman_12_1(4);
    EXPECT_STREQ("IV", actual2);
    free(actual2);

    char *actual3 = intToRoman_12_1(9);
    EXPECT_STREQ("IX", actual3);
    free(actual3);

    char *actual4 = intToRoman_12_1(58);
    EXPECT_STREQ("LVIII", actual4);
    free(actual4);

    char *actual5 = intToRoman_12_1(1994);
    EXPECT_STREQ("MCMXCIV", actual5);
    free(actual5);
}
