#include <gtest/gtest.h>

extern "C" {
#include <valid_palindrome.h>
}

TEST(leetcode_125, normal) {
    EXPECT_TRUE(isPalindrome_125(""));
    EXPECT_TRUE(isPalindrome_125("A man, a plan, a canal: Panama"));
    EXPECT_FALSE(isPalindrome_125("race a car"));
    EXPECT_FALSE(isPalindrome_125("0P"));
}
