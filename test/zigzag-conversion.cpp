#include <gtest/gtest.h>

extern "C" {
#include <zigzag-conversion.h>
}

TEST(leetcode_6, normal) {
    char *str = convert_6("PAYPALISHIRING", 3);
    EXPECT_STREQ(str, "PAHNAPLSIIGYIR");
    free(str);
    str = convert_6("PAYPALISHIRING", 4);
    EXPECT_STREQ(str, "PINALSIGYAHRPI");
    free(str);
}
