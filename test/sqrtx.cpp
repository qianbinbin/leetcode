#include <gtest/gtest.h>

extern "C" {
#include <sqrtx.h>
}

TEST(leetcode_69_1, normal) {
    EXPECT_EQ(mySqrt_69_1(4), 2);
    EXPECT_EQ(mySqrt_69_1(8), 2);
}

TEST(leetcode_69_2, normal) {
    EXPECT_EQ(mySqrt_69_2(4), 2);
    EXPECT_EQ(mySqrt_69_2(8), 2);
}
