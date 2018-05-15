#include <gtest/gtest.h>

extern "C" {
#include <divide-two-integers.h>
}

TEST(leetcode_29, normal) {
    EXPECT_EQ(divide_29(10, 3), 3);
    EXPECT_EQ(divide_29(7, -3), -2);
    EXPECT_EQ(divide_29(INT_MIN, -1), INT_MAX);
    EXPECT_EQ(divide_29(INT_MIN, 1), INT_MIN);
}
