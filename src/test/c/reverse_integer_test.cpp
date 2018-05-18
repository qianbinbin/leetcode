#include <gtest/gtest.h>

extern "C" {
#include <reverse_integer.h>
}

TEST(leetcode_7, normal) {
    EXPECT_EQ(reverse_7(123), 321);
    EXPECT_EQ(reverse_7(-123), -321);
    EXPECT_EQ(reverse_7(120), 21);
    EXPECT_EQ(reverse_7(INT_MIN), 0);
}
