#include <gtest/gtest.h>

extern "C" {
#include "combinations.h"
}

TEST(combinations_test, combine_77_1) {
    int const n1 = 4, k1 = 2;
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> const expected1{{1, 2},
                                                  {1, 3},
                                                  {1, 4},
                                                  {2, 3},
                                                  {2, 4},
                                                  {3, 4}};
    int **actual1 = combine_77_1(n1, k1, &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int const n2 = 1, k2 = 1;
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> const expected2{{1}};
    int **actual2 = combine_77_1(n2, k2, &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);
}
