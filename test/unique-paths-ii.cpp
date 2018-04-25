#include <gtest/gtest.h>

extern "C" {
#include <unique-paths-ii.h>
}

TEST(leetcode_63_1, normal) {
    int *grid[3];
    int l1[3] = {0, 0, 0};
    int l2[3] = {0, 1, 0};
    int l3[3] = {0, 0, 0};
    grid[0] = l1;
    grid[1] = l2;
    grid[2] = l3;
    EXPECT_EQ(uniquePathsWithObstacles_63_1(grid, 3, 3), 2);
}

TEST(leetcode_63_2, normal) {
    int *grid[3];
    int l1[3] = {0, 0, 0};
    int l2[3] = {0, 1, 0};
    int l3[3] = {0, 0, 0};
    grid[0] = l1;
    grid[1] = l2;
    grid[2] = l3;
    EXPECT_EQ(uniquePathsWithObstacles_63_2(grid, 3, 3), 2);
}
