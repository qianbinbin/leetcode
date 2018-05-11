#include <gtest/gtest.h>

extern "C" {
#include <multiply-strings.h>
}

TEST(leetcode_43, normal) {
    char *result1 = multiply_43("2", "3");
    EXPECT_STREQ(result1, "6");
    free(result1);
    char *result2 = multiply_43("123", "456");
    EXPECT_STREQ(result2, "56088");
    free(result2);
    char *result3 = multiply_43("0", "0");
    EXPECT_STREQ(result3, "0");
    free(result3);
}
