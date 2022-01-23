#include <gtest/gtest.h>

extern "C" {
#include "subsets.h"
}

TEST(subsets_test, subsets_78_1) {
    int nums1[] = {1, 2, 3};
    int const numsSize1 = 3;
    int *returnColumnSizes1 = NULL;
    int returnSize1 = 0;
    std::vector<std::vector<int>> const expected1{
            {},
            {1},
            {1, 2},
            {1, 2, 3},
            {1, 3},
            {2},
            {2, 3},
            {3},
    };
    int **actual1 = subsets_78_1(nums1, numsSize1, &returnSize1,
                                 &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i].size(), returnColumnSizes1[i]);
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    free(actual1);

    int nums2[] = {0};
    int const numsSize2 = 1;
    int *returnColumnSizes2 = NULL;
    int returnSize2 = 0;
    std::vector<std::vector<int>> const expected2{
            {},
            {0}
    };
    int **actual2 = subsets_78_1(nums2, numsSize2, &returnSize2,
                                 &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i].size(), returnColumnSizes2[i]);
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    free(actual2);
}
