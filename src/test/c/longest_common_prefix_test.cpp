#include <gtest/gtest.h>

extern "C" {
#include <longest_common_prefix.h>
}

TEST(leetcode_14, empty) {
    char *strs[0] = {};
    char *ret = longestCommonPrefix_14(strs, 0);
    EXPECT_STREQ(ret, "");
    free(ret);
}

TEST(leetcode_14, normal) {
    char *strs[2] = {"qwert", "qwesd"};
    char *ret = longestCommonPrefix_14(strs, 2);
    EXPECT_STREQ(ret, "qwe");
    free(ret);
}
