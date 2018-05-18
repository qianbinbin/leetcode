#include <gtest/gtest.h>

extern "C" {
#include <string_to_integer_atoi.h>
}

TEST(leetcode_8, normal) {
    EXPECT_EQ(myAtoi_8(""), 0);
    EXPECT_EQ(myAtoi_8("-02194"), -2194);
    EXPECT_EQ(myAtoi_8("   +00002.5"), 2);
}

TEST(leetcode_8, overflow) {
    EXPECT_EQ(myAtoi_8("2147483646"), 2147483646);
    EXPECT_EQ(myAtoi_8("2147483647"), INT_MAX);
    EXPECT_EQ(myAtoi_8("2147483648"), INT_MAX);
    EXPECT_EQ(myAtoi_8("-2147483647"), -2147483647);
    EXPECT_EQ(myAtoi_8("-2147483648"), INT_MIN);
    EXPECT_EQ(myAtoi_8("-2147483649"), INT_MIN);
}
