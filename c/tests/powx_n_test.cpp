#include <gtest/gtest.h>

extern "C" {
#include "powx_n.h"
}

TEST(powx_n_test, myPow_50_1) {
    EXPECT_DOUBLE_EQ(1024.00000, myPow_50_1(2.00000, 10));
    EXPECT_DOUBLE_EQ(9.26100, myPow_50_1(2.10000, 3));
    EXPECT_DOUBLE_EQ(0.25000, myPow_50_1(2.00000, -2));
}
