#include <gtest/gtest.h>

extern "C" {
#include "reverse_integer.h"
}

TEST(reverse_integer_test, reverse_7_1) {
    EXPECT_EQ(reverse_7_1(123), 321);
    EXPECT_EQ(reverse_7_1(-123), -321);
    EXPECT_EQ(reverse_7_1(120), 21);
}
