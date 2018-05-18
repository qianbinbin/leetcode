#include <gtest/gtest.h>

extern "C" {
#include <interleaving_string.h>
}

TEST(leetcode_97, normal) {
    EXPECT_TRUE(isInterleave_97("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_FALSE(isInterleave_97("aabcc", "dbbca", "aadbbbaccc"));
}
