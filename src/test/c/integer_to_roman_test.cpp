#include <gtest/gtest.h>

extern "C" {
#include <integer_to_roman.h>
}

TEST(leetcode_12, normal) {
    char *ret = intToRoman_12(386);
    EXPECT_STREQ(ret, "CCCLXXXVI");
    free(ret);
}
