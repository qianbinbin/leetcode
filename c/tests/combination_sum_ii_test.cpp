#include <gtest/gtest.h>

extern "C" {
#include "combination_sum_ii.h"
}

TEST(combination_sum_ii_test, combinationSum2_40_1) {
    int candidates1[] = {10, 1, 2, 7, 6, 1, 5};
    int const candidatesSize1 = 7, target1 = 8;
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{1, 1, 6},
                                            {1, 2, 5},
                                            {1, 7},
                                            {2, 6}};
    int **actual1 = combinationSum2_40_1(candidates1, candidatesSize1,
                                         target1, &returnSize1,
                                         &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int candidates2[] = {2, 5, 2, 1, 2};
    int const candidatesSize2 = 5, target2 = 5;
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{1, 2, 2},
                                            {5}};
    int **actual2 = combinationSum2_40_1(candidates2, candidatesSize2,
                                         target2, &returnSize2,
                                         &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);
}
