#include <gtest/gtest.h>

extern "C" {
#include "longest_palindromic_substring.h"
}

TEST(longest_palindromic_substring_test, longestPalindrome_5_1) {
    char *ret = longestPalindrome_5_1("babad");
    EXPECT_STREQ(ret, "aba");
    free(ret);
    ret = longestPalindrome_5_1("cbbd");
    EXPECT_STREQ(ret, "bb");
    free(ret);
}
