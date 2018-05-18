#include <gtest/gtest.h>

extern "C" {
#include <longest_palindromic_substring.h>
}

TEST(leetcode_5_1, normal) {
    char *ret = longestPalindrome_5_1("babad");
    EXPECT_STREQ(ret, "bab");
    free(ret);
    ret = longestPalindrome_5_1("cbbd");
    EXPECT_STREQ(ret, "bb");
    free(ret);
}

TEST(leetcode_5_2, normal) {
    char *ret = longestPalindrome_5_2("babad");
    EXPECT_STREQ(ret, "bab");
    free(ret);
    ret = longestPalindrome_5_2("cbbd");
    EXPECT_STREQ(ret, "bb");
    free(ret);
    ret = longestPalindrome_5_2("");
    EXPECT_STREQ(ret, "");
    free(ret);
    ret = longestPalindrome_5_2("b");
    EXPECT_STREQ(ret, "b");
    free(ret);
}
