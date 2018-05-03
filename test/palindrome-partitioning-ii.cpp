#include <gtest/gtest.h>

extern "C" {
#include <palindrome-partitioning-ii.h>
}

TEST(leetcode_132, normal) {
    EXPECT_EQ(minCut_132("aab"), 1);
}
