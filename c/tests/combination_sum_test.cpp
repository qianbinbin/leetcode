#include <gtest/gtest.h>

extern "C" {
#include "combination_sum.h"
}

TEST(combination_sum_test, combinationSum_39_1) {
    int candidates1[] = {2, 3, 6, 7};
    int const candidatesSize1 = 4, target1 = 7;
    std::vector<std::vector<int>> expected1{{2, 2, 3},
                                            {7}};
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    int **actual1 = combinationSum_39_1(candidates1, candidatesSize1,
                                        target1, &returnSize1,
                                        &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i],
                  std::vector<int>(actual1[i],
                                   actual1[i] + returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int candidates2[] = {2, 3, 5};
    int const candidatesSize2 = 3, target2 = 8;
    std::vector<std::vector<int>> expected2{{2, 2, 2, 2},
                                            {2, 3, 3},
                                            {3, 5}};
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    int **actual2 = combinationSum_39_1(candidates2, candidatesSize2,
                                        target2, &returnSize2,
                                        &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i],
                  std::vector<int>(actual2[i],
                                   actual2[i] + returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);

    int candidates3[] = {2};
    int const candidatesSize3 = 1, target3 = 1;
    std::vector<std::vector<int>> expected3;
    int returnSize3 = 0;
    int *returnColumnSizes3 = NULL;
    int **actual3 = combinationSum_39_1(candidates3, candidatesSize3,
                                        target3, &returnSize3,
                                        &returnColumnSizes3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i],
                  std::vector<int>(actual3[i],
                                   actual3[i] + returnColumnSizes3[i]));
        free(actual3[i]);
    }
    free(actual3);
    free(returnColumnSizes3);

    int candidates4[] = {1};
    int const candidatesSize4 = 1, target4 = 1;
    std::vector<std::vector<int>> expected4{{1}};
    int returnSize4 = 0;
    int *returnColumnSizes4 = NULL;
    int **actual4 = combinationSum_39_1(candidates4, candidatesSize4,
                                        target4, &returnSize4,
                                        &returnColumnSizes4);
    ASSERT_EQ(expected4.size(), returnSize4);
    for (int i = 0; i < returnSize4; ++i) {
        EXPECT_EQ(expected4[i],
                  std::vector<int>(actual4[i],
                                   actual4[i] + returnColumnSizes4[i]));
        free(actual4[i]);
    }
    free(actual4);
    free(returnColumnSizes4);

    int candidates5[] = {1};
    int const candidatesSize5 = 1, target5 = 2;
    std::vector<std::vector<int>> expected5{{1, 1}};
    int returnSize5 = 0;
    int *returnColumnSizes5 = NULL;
    int **actual5 = combinationSum_39_1(candidates5, candidatesSize5,
                                        target5, &returnSize5,
                                        &returnColumnSizes5);
    ASSERT_EQ(expected5.size(), returnSize5);
    for (int i = 0; i < returnSize5; ++i) {
        EXPECT_EQ(expected5[i],
                  std::vector<int>(actual5[i],
                                   actual5[i] + returnColumnSizes5[i]));
        free(actual5[i]);
    }
    free(actual5);
    free(returnColumnSizes5);
}
