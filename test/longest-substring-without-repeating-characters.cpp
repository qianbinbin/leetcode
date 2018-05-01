#include <gtest/gtest.h>

extern "C" {
#include <longest-substring-without-repeating-characters.h>
}

TEST(leetcode_3, normal) {
    EXPECT_EQ(lengthOfLongestSubstring_3("abcabcbb"), 3);
    EXPECT_EQ(lengthOfLongestSubstring_3("bbbbb"), 1);
    EXPECT_EQ(lengthOfLongestSubstring_3("pwwkew"), 3);
}
