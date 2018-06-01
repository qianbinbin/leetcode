#include <gtest/gtest.h>

extern "C" {
#include "divide_two_integers.h"
}

TEST(divide_two_integers_test, divide_29_1) {
    EXPECT_EQ(divide_29_1(10, 3), 3);
    EXPECT_EQ(divide_29_1(7, -3), -2);
}
