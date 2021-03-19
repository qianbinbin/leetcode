#include <gtest/gtest.h>

extern "C" {
#include "implement_strstr.h"
}

TEST(implement_strstr_test, strStr_28_1) {
    EXPECT_EQ(2, strStr_28_1("hello", "ll"));
    EXPECT_EQ(-1, strStr_28_1("aaaaa", "bba"));
    EXPECT_EQ(0, strStr_28_1("", ""));
}

TEST(implement_strstr_test, strStr_28_2) {
    EXPECT_EQ(2, strStr_28_2("hello", "ll"));
    EXPECT_EQ(-1, strStr_28_2("aaaaa", "bba"));
    EXPECT_EQ(0, strStr_28_2("", ""));
}
