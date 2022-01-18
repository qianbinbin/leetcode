#include <gtest/gtest.h>

extern "C" {
#include "minimum_path_sum.h"
}

TEST(minimum_path_sum_test, minPathSum_64_1) {
    int grid1[3][3] = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    int *g1[3] = {grid1[0], grid1[1], grid1[2]};
    int const gridSize1 = 3;
    int gridColSize1[] = {3, 3, 3};
    int const expected1 = 7;
    EXPECT_EQ(expected1, minPathSum_64_1(g1, gridSize1, gridColSize1));

    int grid2[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    int *g2[3] = {grid2[0], grid2[1]};
    int const gridSize2 = 2;
    int gridColSize2[] = {3, 3, 3};
    int const expected2 = 12;
    EXPECT_EQ(expected2, minPathSum_64_1(g2, gridSize2, gridColSize2));
}
