#include <gtest/gtest.h>

extern "C" {
#include <implement-strstr.h>
}

TEST(leetcode_28_1, normal) {
    EXPECT_EQ(strStr_28_1("hello", ""), 0);
    EXPECT_EQ(strStr_28_1("", "a"), -1);
    EXPECT_EQ(strStr_28_1("hello", "ll"), 2);
    EXPECT_EQ(strStr_28_1("aaaaa", "bba"), -1);
}
