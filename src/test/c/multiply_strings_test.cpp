#include <gtest/gtest.h>

extern "C" {
#include "multiply_strings.h"
}

TEST(multiply_strings_test, multiply_43_1) {
    char *result1 = multiply_43_1("2", "3");
    EXPECT_STREQ(result1, "6");
    free(result1);
    char *result2 = multiply_43_1("123", "456");
    EXPECT_STREQ(result2, "56088");
    free(result2);
}
