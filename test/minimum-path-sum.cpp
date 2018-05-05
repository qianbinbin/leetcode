#include <gtest/gtest.h>

extern "C" {
#include <minimum-path-sum.h>
}

TEST(leetcode_64, normal) {
    int nums[3][3] = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    int *grid[3] = {nums[0], nums[1], nums[2]};
    EXPECT_EQ(minPathSum_64(grid, 3, 3), 7);
}
