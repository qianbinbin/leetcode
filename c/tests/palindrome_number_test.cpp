#include <gtest/gtest.h>

extern "C" {
#include "palindrome_number.h"
}

TEST(palindrome_number_test, isPalindrome_9_1) {
    EXPECT_TRUE(isPalindrome_9_1(121));
    EXPECT_FALSE(isPalindrome_9_1(-121));
    EXPECT_FALSE(isPalindrome_9_1(10));
}
