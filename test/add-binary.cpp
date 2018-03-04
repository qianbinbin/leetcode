#include <gtest/gtest.h>

extern "C" {
#include <add-binary.h>
}

TEST(leetcode_67, normal) {
    char *ret = addBinary_67("1", "11");
    EXPECT_STREQ(ret, "100");
    free(ret);
    ret = addBinary_67("00", "0");
    EXPECT_STREQ(ret, "0");
    free(ret);
}
