#include <gtest/gtest.h>

extern "C" {
#include "implement_strstr.h"
}

TEST(implement_strstr_test, strStr_28_1) {
    EXPECT_EQ(strStr_28_1("hello", "ll"), 2);
    EXPECT_EQ(strStr_28_1("aaaaa", "bba"), -1);
}

TEST(implement_strstr_test, strStr_28_2) {
    EXPECT_EQ(strStr_28_2("hello", "ll"), 2);
    EXPECT_EQ(strStr_28_2("aaaaa", "bba"), -1);
}
