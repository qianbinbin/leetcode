#include <gtest/gtest.h>

extern "C" {
#include <triangle.h>
}

TEST(leetcode_120, normal) {
    int row0[] = {2};
    int row1[] = {3, 4};
    int row2[] = {6, 5, 7};
    int row3[] = {4, 1, 8, 3};
    int *triangle[] = {row0, row1, row2, row3};
    int cols[] = {1, 2, 3, 4};
    EXPECT_EQ(minimumTotal_120(triangle, 4, cols), 11);
}