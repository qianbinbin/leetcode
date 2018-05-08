#include <gtest/gtest.h>

extern "C" {
#include <palindrome-number.h>
}

TEST(leetcode_9, normal) {
    EXPECT_TRUE(isPalindrome_9(121));
    EXPECT_FALSE(isPalindrome_9(-121));
    EXPECT_FALSE(isPalindrome_9(10));
}
