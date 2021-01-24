#include <gtest/gtest.h>

extern "C" {
#include "string_to_integer_atoi.h"
}

TEST(string_to_integer_atoi_test, myAtoi_8_1) {
    EXPECT_EQ(42, myAtoi_8_1("42"));
    EXPECT_EQ(-42, myAtoi_8_1("-42"));
    EXPECT_EQ(4193, myAtoi_8_1("4193 with words"));
    EXPECT_EQ(0, myAtoi_8_1("words and 987"));
    EXPECT_EQ(INT_MIN, myAtoi_8_1("-91283472332"));
}
