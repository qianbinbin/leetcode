#include <gtest/gtest.h>

extern "C" {
#include <scramble-string.h>
}

TEST(leetcode_87_1, normal) {
    EXPECT_TRUE(isScramble_87_1("great", "rgeat"));
    EXPECT_FALSE(isScramble_87_1("abcde", "caebd"));
    EXPECT_FALSE(isScramble_87_1("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba"));
}

TEST(leetcode_87_2, normal) {
    EXPECT_TRUE(isScramble_87_2("great", "rgeat"));
    EXPECT_FALSE(isScramble_87_2("abcde", "caebd"));
    EXPECT_FALSE(isScramble_87_2("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba"));
}
