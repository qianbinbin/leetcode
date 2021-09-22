#include <gtest/gtest.h>

extern "C" {
#include "insert_interval.h"
}

TEST(insert_interval_test, insert_57_1) {
    int intervals1[][2] = {{1, 3},
                           {6, 9}}, intervalsSize1 = 2;
    int *pIntervals1[] = {intervals1[0], intervals1[1]};
    int newInterval1[] = {2, 5};
    const std::vector<std::vector<int>> expected1{{1, 5},
                                                  {6, 9}};
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    int **actual1 = insert_57_1(pIntervals1, intervalsSize1, NULL, newInterval1,
                                2, &returnSize1,
                                &returnColumnSizes1);
    EXPECT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] + 2));
        EXPECT_EQ(2, returnColumnSizes1[i]);
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);
}
