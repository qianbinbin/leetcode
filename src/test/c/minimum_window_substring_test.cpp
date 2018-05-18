#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <minimum_window_substring.h>
}

TEST(leetcode_76, normal) {
    char *window = minWindow_76("ADOBECODEBANC", "ABC");
    EXPECT_STREQ(window, "BANC");
    free(window);
}
