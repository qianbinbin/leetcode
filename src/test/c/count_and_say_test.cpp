#include <gtest/gtest.h>

extern "C" {
#include <count_and_say.h>
}

TEST(leetcode_38, normal) {
    char *ret = countAndSay_38(7);
    EXPECT_STREQ(ret, "13112221");
    free(ret);
}
