#include <gtest/gtest.h>

extern "C" {
#include "multiply_strings.h"
}

TEST(multiply_strings_test, multiply_43_1) {
    char *actual1 = multiply_43_1("2", "3");
    EXPECT_STREQ("6", actual1);
    free(actual1);

    char *actual2 = multiply_43_1("123", "456");
    EXPECT_STREQ("56088", actual2);
    free(actual2);
}
