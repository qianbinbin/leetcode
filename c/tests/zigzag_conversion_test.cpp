#include <gtest/gtest.h>

extern "C" {
#include "zigzag_conversion.h"
}

TEST(zigzag_conversion_test, convert_6_1) {
    char *actual1 = convert_6_1("PAYPALISHIRING", 3);
    EXPECT_STREQ("PAHNAPLSIIGYIR", actual1);
    free(actual1);

    char *actual2 = convert_6_1("PAYPALISHIRING", 4);
    EXPECT_STREQ("PINALSIGYAHRPI", actual2);
    free(actual2);

    char *actual3 = convert_6_1("A", 1);
    EXPECT_STREQ("A", actual3);
    free(actual3);
}
