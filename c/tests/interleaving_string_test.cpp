#include <gtest/gtest.h>

extern "C" {
#include "interleaving_string.h"
}

TEST(interleaving_string_test, isInterleave_97_1) {
    EXPECT_TRUE(isInterleave_97_1("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_FALSE(isInterleave_97_1("aabcc", "dbbca", "aadbbbaccc"));
    EXPECT_TRUE(isInterleave_97_1("", "", ""));
}
