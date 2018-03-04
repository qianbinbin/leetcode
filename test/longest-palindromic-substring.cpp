#include <gtest/gtest.h>

extern "C" {
#include <longest-palindromic-substring.h>
}

TEST(leetcode_5_1, normal) {
    char *ret = longestPalindrome_5_1("babad");
    EXPECT_STREQ(ret, "bab");
    free(ret);
    ret = longestPalindrome_5_1("cbbd");
    EXPECT_STREQ(ret, "bb");
    free(ret);
}
