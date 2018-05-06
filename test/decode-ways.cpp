#include <gtest/gtest.h>

extern "C" {
#include <decode-ways.h>
}

TEST(leetcode_91, normal) {
    EXPECT_EQ(numDecodings_91("12"), 2);
    EXPECT_EQ(numDecodings_91("226"), 3);
    EXPECT_EQ(numDecodings_91("2206212"), 3);
    EXPECT_EQ(numDecodings_91("100"), 0);
}
