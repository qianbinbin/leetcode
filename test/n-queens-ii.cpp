#include <gtest/gtest.h>

extern "C" {
#include <n-queens-ii.h>
}

TEST(leetcode_52, normal) {
    EXPECT_EQ(totalNQueens_52(4), 2);
}
