#include <gtest/gtest.h>

extern "C" {
#include "sqrtx.h"
}

TEST(sqrtx_test, mySqrt_69_1) {
    EXPECT_EQ(mySqrt_69_1(4), 2);
    EXPECT_EQ(mySqrt_69_1(8), 2);
}

TEST(sqrtx_test, mySqrt_69_2) {
    EXPECT_EQ(mySqrt_69_2(4), 2);
    EXPECT_EQ(mySqrt_69_2(8), 2);
}
