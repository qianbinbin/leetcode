#include <gtest/gtest.h>

extern "C" {
#include "valid_palindrome.h"
}

TEST(valid_palindrome_test, isPalindrome_125_1) {
    EXPECT_TRUE(isPalindrome_125_1("A man, a plan, a canal: Panama"));
    EXPECT_FALSE(isPalindrome_125_1("race a car"));
    EXPECT_TRUE(isPalindrome_125_1(" "));
}
