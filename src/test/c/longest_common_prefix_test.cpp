#include <gtest/gtest.h>

extern "C" {
#include "longest_common_prefix.h"
}

TEST(longest_common_prefix_test, longestCommonPrefix_14_1) {
    char *strs1[3] = {"flower", "flow", "flight"};
    char *ret1 = longestCommonPrefix_14_1(strs1, 3);
    EXPECT_STREQ(ret1, "fl");
    free(ret1);
    char *strs2[3] = {"dog", "racecar", "car"};
    char *ret2 = longestCommonPrefix_14_1(strs2, 3);
    EXPECT_STREQ(ret2, "");
    free(ret2);
}
