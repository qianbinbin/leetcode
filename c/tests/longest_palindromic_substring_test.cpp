#include <gtest/gtest.h>

extern "C" {
#include "longest_palindromic_substring.h"
}

TEST(longest_palindromic_substring_test, longestPalindrome_5_1) {
    char *actual1 = longestPalindrome_5_1("babad");
    EXPECT_STREQ("bab", actual1);
    free(actual1);

    char *actual2 = longestPalindrome_5_1("cbbd");
    EXPECT_STREQ("bb", actual2);
    free(actual2);

    char *actual3 = longestPalindrome_5_1("a");
    EXPECT_STREQ("a", actual3);
    free(actual3);

    char *actual4 = longestPalindrome_5_1("ac");
    EXPECT_STREQ("a", actual4);
    free(actual4);
}
