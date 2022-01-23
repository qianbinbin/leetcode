#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "minimum_window_substring.h"
}

TEST(minimum_window_substring_test, minWindow_76_1) {
    char *actual1 = minWindow_76_1("ADOBECODEBANC", "ABC");
    EXPECT_STREQ("BANC", actual1);
    free(actual1);

    char *actual2 = minWindow_76_1("a", "a");
    EXPECT_STREQ("a", actual2);
    free(actual2);

    char *actual3 = minWindow_76_1("a", "aa");
    EXPECT_STREQ("", actual3);
    free(actual3);
}
