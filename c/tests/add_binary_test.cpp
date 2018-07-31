#include <gtest/gtest.h>

extern "C" {
#include "add_binary.h"
}

TEST(add_binary_test, addBinary_67_1) {
    char *ret1 = addBinary_67_1("11", "1");
    EXPECT_STREQ(ret1, "100");
    free(ret1);

    char *ret2 = addBinary_67_1("1010", "1011");
    EXPECT_STREQ(ret2, "10101");
    free(ret2);
}
