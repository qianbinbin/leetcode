#include <gtest/gtest.h>

extern "C" {
#include "subsets_ii.h"
}

TEST(subsets_ii_test, subsetsWithDup_90_1) {
    int nums1[] = {1, 2, 2};
    int returnSize1 = 0;
    int *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{},
                                            {1},
                                            {1, 2},
                                            {1, 2, 2},
                                            {2},
                                            {2, 2}};
    int **actual1 = subsetsWithDup_90_1(nums1, sizeof(nums1) / sizeof(nums1[0]),
                                        &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(returnColumnSizes1);
    free(actual1);

    int nums2[] = {0};
    int returnSize2 = 0;
    int *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{},
                                            {0}};
    int **actual2 = subsetsWithDup_90_1(nums2, sizeof(nums2) / sizeof(nums2[0]),
                                        &returnSize2, &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(returnColumnSizes2);
    free(actual2);
}
