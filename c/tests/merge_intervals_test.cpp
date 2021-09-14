#include <gtest/gtest.h>

extern "C" {
#include "merge_intervals.h"
}

TEST(merge_intervals_test, merge_56_1) {
    int intervals1[][2] = {{1,  3},
                           {2,  6},
                           {8,  10},
                           {15, 18}}, intervalSize1 = 4;
    int *pIntervals1[] = {intervals1[0], intervals1[1], intervals1[2],
                          intervals1[3]};
    const std::vector<std::vector<int>> expected1{{1,  6},
                                                  {8,  10},
                                                  {15, 18}};
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    int **actual1 = merge_56_1(pIntervals1, intervalSize1, NULL, &returnSize1,
                               &returnColumnSizes1);
    EXPECT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] + 2));
        EXPECT_EQ(2, returnColumnSizes1[i]);
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int intervals2[][2] = {{1, 4},
                           {4, 5}}, intervalSize2 = 2;
    int *pIntervals2[] = {intervals2[0], intervals2[1]};
    const std::vector<std::vector<int>> expected2{{1, 5}};
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    int **actual2 = merge_56_1(pIntervals2, intervalSize2, NULL, &returnSize2,
                               &returnColumnSizes2);
    EXPECT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] + 2));
        EXPECT_EQ(2, returnColumnSizes2[i]);
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);
}
