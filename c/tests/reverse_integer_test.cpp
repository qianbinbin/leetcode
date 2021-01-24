#include <gtest/gtest.h>

extern "C" {
#include "reverse_integer.h"
}

TEST(reverse_integer_test, reverse_7_1) {
    EXPECT_EQ(321, reverse_7_1(123));
    EXPECT_EQ(-321, reverse_7_1(-123));
    EXPECT_EQ(21, reverse_7_1(120));
    EXPECT_EQ(0, reverse_7_1(0));
}
