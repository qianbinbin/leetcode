#include <gtest/gtest.h>

extern "C" {
#include "reverse_words_in_a_string.h"
}

TEST(reverse_words_in_a_string_test, reverseWords_151_1) {
    char s[] = "the sky is blue";
    reverseWords_151_1(s);
    EXPECT_STREQ(s, "blue is sky the");
}
