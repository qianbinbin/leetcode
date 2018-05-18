#include <gtest/gtest.h>

extern "C" {
#include <palindrome_partitioning_ii.h>
}

TEST(leetcode_132, normal) {
    EXPECT_EQ(minCut_132("aab"), 1);
}
