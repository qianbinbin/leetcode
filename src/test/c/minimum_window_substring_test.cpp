#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "minimum_window_substring.h"
}

TEST(minimum_window_substring_test, minWindow_76_1) {
    char *window = minWindow_76_1("ADOBECODEBANC", "ABC");
    EXPECT_STREQ(window, "BANC");
    free(window);
}
