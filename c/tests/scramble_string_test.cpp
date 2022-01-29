#include <gtest/gtest.h>

extern "C" {
#include "scramble_string.h"
}

TEST(scramble_string_test, isScramble_87_1) {
    EXPECT_TRUE(isScramble_87_1("great", "rgeat"));
    EXPECT_FALSE(isScramble_87_1("abcde", "caebd"));
    EXPECT_TRUE(isScramble_87_1("a", "a"));
}

TEST(scramble_string_test, isScramble_87_2) {
    EXPECT_TRUE(isScramble_87_2("great", "rgeat"));
    EXPECT_FALSE(isScramble_87_2("abcde", "caebd"));
    EXPECT_TRUE(isScramble_87_2("a", "a"));
}
