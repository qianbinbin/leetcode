#include <gtest/gtest.h>

extern "C" {
#include "unique_paths_ii.h"
}

TEST(unique_paths_ii_test, uniquePathsWithObstacles_63_1) {
    int grid[][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    int *p_grid[3] = {grid[0], grid[1], grid[2]};
    EXPECT_EQ(uniquePathsWithObstacles_63_1(p_grid, 3, 3), 2);
}
