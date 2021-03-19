#include <gtest/gtest.h>

extern "C" {
#include "divide_two_integers.h"
}

TEST(divide_two_integers_test, divide_29_1) {
    EXPECT_EQ(3, divide_29_1(10, 3));
    EXPECT_EQ(-2, divide_29_1(7, -3));
    EXPECT_EQ(0, divide_29_1(0, 1));
    EXPECT_EQ(1, divide_29_1(1, 1));
}
