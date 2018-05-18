#include <gtest/gtest.h>

extern "C" {
#include <powx_n.h>
}

TEST(leetcode_50, normal) {
    EXPECT_DOUBLE_EQ(myPow_50(2.00000, 10), 1024.00000);
    EXPECT_DOUBLE_EQ(myPow_50(2.10000, 3), 9.26100);
    EXPECT_DOUBLE_EQ(myPow_50(2.00000, -2), 0.25000);
    EXPECT_DOUBLE_EQ(myPow_50(0.00001, 2147483647), 0.0);
    EXPECT_DOUBLE_EQ(myPow_50(1.00000, -2147483648), 1.0);
}
