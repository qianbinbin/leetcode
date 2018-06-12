#include <gtest/gtest.h>

extern "C" {
#include "wildcard_matching.h"
}

TEST(wildcard_matching_test, isMatch_44_1) {
    EXPECT_FALSE(isMatch_44_1("aa", "a"));
    EXPECT_TRUE(isMatch_44_1("aa", "*"));
    EXPECT_FALSE(isMatch_44_1("cb", "?a"));
    EXPECT_TRUE(isMatch_44_1("adceb", "*a*b"));
    EXPECT_FALSE(isMatch_44_1("acdcb", "a*c?b"));
}

TEST(wildcard_matching_test, isMatch_44_2) {
    EXPECT_FALSE(isMatch_44_2("aa", "a"));
    EXPECT_TRUE(isMatch_44_2("aa", "*"));
    EXPECT_FALSE(isMatch_44_2("cb", "?a"));
    EXPECT_TRUE(isMatch_44_2("adceb", "*a*b"));
    EXPECT_FALSE(isMatch_44_2("acdcb", "a*c?b"));
}