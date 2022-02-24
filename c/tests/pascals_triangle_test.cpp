#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "pascals_triangle.h"
}

TEST(pascals_triangle_test, generate_118_1) {
    int const numRows1 = 5;
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{1},
                                            {1, 1},
                                            {1, 2, 1},
                                            {1, 3, 3, 1},
                                            {1, 4, 6, 4, 1}};
    int **actual1 = generate_118_1(numRows1, &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    free(actual1);

    int const numRows2 = 1;
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{1}};
    int **actual2 = generate_118_1(numRows2, &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    free(actual2);
}
