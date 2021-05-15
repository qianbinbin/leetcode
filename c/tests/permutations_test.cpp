#include <gtest/gtest.h>

extern "C" {
#include "permutations.h"
}

TEST(permutations_test, permute_46_1) {
    int nums1[] = {1, 2, 3};
    int const numsSize1 = 3;
    int returnSize1 = 0, *returnColumnSizes1 = NULL;
    std::vector<std::vector<int>> expected1{{1, 2, 3},
                                            {1, 3, 2},
                                            {2, 1, 3},
                                            {2, 3, 1},
                                            {3, 1, 2},
                                            {3, 2, 1}};
    int **actual1 = permute_46_1(nums1, numsSize1, &returnSize1,
                                 &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSizes1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);

    int nums2[] = {0, 1};
    int const numsSize2 = 2;
    int returnSize2 = 0, *returnColumnSizes2 = NULL;
    std::vector<std::vector<int>> expected2{{0, 1},
                                            {1, 0}};
    int **actual2 = permute_46_1(nums2, numsSize2, &returnSize2,
                                 &returnColumnSizes2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSizes2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSizes2);

    int nums3[] = {1};
    int const numsSize3 = 1;
    int returnSize3 = 0, *returnColumnSizes3 = NULL;
    std::vector<std::vector<int>> expected3{{1}};
    int **actual3 = permute_46_1(nums3, numsSize3, &returnSize3,
                                 &returnColumnSizes3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], std::vector<int>(actual3[i], actual3[i] +
                                                             returnColumnSizes3[i]));
        free(actual3[i]);
    }
    free(actual3);
    free(returnColumnSizes3);
}
