#include <gtest/gtest.h>

extern "C" {
#include "add_binary.h"
}

TEST(add_binary_test, addBinary_67_1) {
    char *actual1 = addBinary_67_1("11", "1");
    EXPECT_STREQ("100", actual1);
    free(actual1);

    char *actual2 = addBinary_67_1("1010", "1011");
    EXPECT_STREQ("10101", actual2);
    free(actual2);
}
