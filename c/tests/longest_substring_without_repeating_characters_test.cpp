#include <gtest/gtest.h>

extern "C" {
#include "longest_substring_without_repeating_characters.h"
}

TEST(longest_substring_without_repeating_characters_test,
     lengthOfLongestSubstring_3_1) {
    EXPECT_EQ(3, lengthOfLongestSubstring_3_1("abcabcbb"));
    EXPECT_EQ(1, lengthOfLongestSubstring_3_1("bbbbb"));
    EXPECT_EQ(3, lengthOfLongestSubstring_3_1("pwwkew"));
    EXPECT_EQ(0, lengthOfLongestSubstring_3_1(""));
}
