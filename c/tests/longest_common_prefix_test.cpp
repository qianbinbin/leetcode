#include <gtest/gtest.h>

extern "C" {
#include "longest_common_prefix.h"
}

TEST(longest_common_prefix_test, longestCommonPrefix_14_1) {
    char *strs1[3] = {"flower", "flow", "flight"};
    char *actual1 = longestCommonPrefix_14_1(strs1, 3);
    EXPECT_STREQ("fl", actual1);
    free(actual1);

    char *strs2[3] = {"dog", "racecar", "car"};
    char *actual2 = longestCommonPrefix_14_1(strs2, 3);
    EXPECT_STREQ("", actual2);
    free(actual2);
}
