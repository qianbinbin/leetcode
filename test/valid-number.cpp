#include <gtest/gtest.h>

extern "C" {
#include <valid-number.h>
}

TEST(leetcode_65, normal) {
    char *s = "   +.4523253e-2131   ";
    EXPECT_TRUE(isNumber_65(s));
    EXPECT_FALSE(isNumber_65("+"));
    EXPECT_FALSE(isNumber_65("-"));
    EXPECT_FALSE(isNumber_65("e"));
    EXPECT_FALSE(isNumber_65("e9"));
    EXPECT_FALSE(isNumber_65("0e"));
}
