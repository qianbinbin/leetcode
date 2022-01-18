#include <gtest/gtest.h>

extern "C" {
#include "valid_number.h"
}

TEST(valid_number_test, isNumber_65_1) {
    EXPECT_TRUE(isNumber_65_1("0"));
    EXPECT_FALSE(isNumber_65_1("e"));
    EXPECT_FALSE(isNumber_65_1("."));
}
