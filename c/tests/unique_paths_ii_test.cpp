#include <gtest/gtest.h>

extern "C" {
#include "unique_paths_ii.h"
}

TEST(unique_paths_ii_test, uniquePathsWithObstacles_63_1) {
    int obstacleGrid1[][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    int *o1[3] = {obstacleGrid1[0], obstacleGrid1[1],
                  obstacleGrid1[2]};
    int obstacleGridColSize1[] = {3, 3, 3};
    int const obstacleGridSize1 = 3;
    int const expected1 = 2;
    EXPECT_EQ(expected1, uniquePathsWithObstacles_63_1(o1, obstacleGridSize1,
                                                       obstacleGridColSize1));

    int obstacleGrid2[][2] = {
            {0, 1},
            {0, 0}
    };
    int *o2[2] = {obstacleGrid2[0], obstacleGrid2[1]};
    int obstacleGridColSize2[] = {2, 2};
    int const obstacleGridSize2 = 2;
    int const expected2 = 1;
    EXPECT_EQ(expected2, uniquePathsWithObstacles_63_1(o2, obstacleGridSize2,
                                                       obstacleGridColSize2));
}
