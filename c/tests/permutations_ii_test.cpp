#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "permutations_ii.h"
}

TEST(permutations_ii_test, permuteUnique_47_1) {
    int nums1[] = {1, 1, 2};
    int const numsSize1 = 3;
    int returnSize1 = 0, *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{1, 1, 2},
                                            {1, 2, 1},
                                            {2, 1, 1}};
    int **actual1 = permuteUnique_47_1(nums1, numsSize1, &returnSize1,
                                       &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int nums2[] = {1, 2, 3};
    int const numsSize2 = 3;
    int returnSize2 = 0, *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{1, 2, 3},
                                            {1, 3, 2},
                                            {2, 1, 3},
                                            {2, 3, 1},
                                            {3, 1, 2},
                                            {3, 2, 1}};
    int **actual2 = permuteUnique_47_1(nums2, numsSize2, &returnSize2,
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
