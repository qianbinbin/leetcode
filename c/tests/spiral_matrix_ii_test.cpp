#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "spiral_matrix_ii.h"
}

TEST(spiral_matrix_ii_test, generateMatrix_59_1) {
    int const n1 = 3;
    int returnSize1 = 0, *returnColumnSizes1 = NULL;
    int **actual1 = generateMatrix_59_1(n1, &returnSize1, &returnColumnSizes1);
    std::vector<std::vector<int>> expected1{{1, 2, 3},
                                            {8, 9, 4},
                                            {7, 6, 5}};
    EXPECT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);
}
