#include <gtest/gtest.h>

extern "C" {
#include "length_of_last_word.h"
}

TEST(length_of_last_word_test, lengthOfLastWord_58_1) {
    EXPECT_EQ(lengthOfLastWord_58_1("Hello World"), 5);
}