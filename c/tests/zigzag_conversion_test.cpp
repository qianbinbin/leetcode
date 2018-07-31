#include <gtest/gtest.h>

extern "C" {
#include "zigzag_conversion.h"
}

TEST(zigzag_conversion_test, convert_6_1) {
    char *str = convert_6_1("PAYPALISHIRING", 3);
    EXPECT_STREQ(str, "PAHNAPLSIIGYIR");
    free(str);
    str = convert_6_1("PAYPALISHIRING", 4);
    EXPECT_STREQ(str, "PINALSIGYAHRPI");
    free(str);
}
