#include <gtest/gtest.h>

extern "C" {
#include "valid_number.h"
}

TEST(valid_number_test, isNumber_65_1) {
    EXPECT_TRUE(isNumber_65_1("0"));
    EXPECT_TRUE(isNumber_65_1(" 0.1 "));
    EXPECT_FALSE(isNumber_65_1("abc"));
    EXPECT_FALSE(isNumber_65_1("1 a"));
    EXPECT_TRUE(isNumber_65_1("2e10"));
}
