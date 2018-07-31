#include <gtest/gtest.h>

extern "C" {
#include "string_to_integer_atoi.h"
}

TEST(string_to_integer_atoi_test, myAtoi_8_1) {
    EXPECT_EQ(myAtoi_8_1("42"), 42);
    EXPECT_EQ(myAtoi_8_1("-42"), -42);
    EXPECT_EQ(myAtoi_8_1("4193 with words"), 4193);
    EXPECT_EQ(myAtoi_8_1("words and 987"), 0);
    EXPECT_EQ(myAtoi_8_1("-91283472332"), -2147483648);
}
