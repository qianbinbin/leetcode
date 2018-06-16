#include <gtest/gtest.h>

extern "C" {
#include "powx_n.h"
}

TEST(powx_n_test, myPow_50_1) {
    EXPECT_DOUBLE_EQ(myPow_50_1(2.00000, 10), 1024.00000);
    EXPECT_DOUBLE_EQ(myPow_50_1(2.10000, 3), 9.26100);
    EXPECT_DOUBLE_EQ(myPow_50_1(2.00000, -2), 0.25000);
}
