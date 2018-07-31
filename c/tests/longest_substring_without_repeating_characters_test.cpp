#include <gtest/gtest.h>

extern "C" {
#include "longest_substring_without_repeating_characters.h"
}

TEST(longest_substring_without_repeating_characters_test, lengthOfLongestSubstring_3_1) {
    EXPECT_EQ(lengthOfLongestSubstring_3_1("abcabcbb"), 3);
    EXPECT_EQ(lengthOfLongestSubstring_3_1("bbbbb"), 1);
    EXPECT_EQ(lengthOfLongestSubstring_3_1("pwwkew"), 3);
}
