#include <gtest/gtest.h>

extern "C" {
#include "4sum.h"
}

TEST(four_sum_test, fourSum_18_1) {
    int nums1[] = {1, 0, -1, 0, -2, 2};
    int const numsSize1 = 6, target1 = 0;
    int returnSize1 = 0, *returnColumnSize1 = nullptr;
    std::vector<std::vector<int>> const expected1{
            {-2, -1, 1, 2},
            {-2, 0,  0, 2},
            {-1, 0,  0, 1}
    };
    int **actual1 = fourSum_18_1(nums1, numsSize1, target1, &returnSize1,
                                 &returnColumnSize1);
    EXPECT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], std::vector<int>(actual1[i], actual1[i] +
                                                             returnColumnSize1[i]));
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSize1);

    int nums2[] = {};
    int const numsSize2 = 0, target2 = 0;
    int returnSize2 = 0, *returnColumnSize2 = nullptr;
    std::vector<std::vector<int>> const expected2;
    int **actual2 = fourSum_18_1(nums2, numsSize2, target2, &returnSize2,
                                 &returnColumnSize2);
    EXPECT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], std::vector<int>(actual2[i], actual2[i] +
                                                             returnColumnSize2[i]));
        free(actual2[i]);
    }
    free(actual2);
    free(returnColumnSize2);
}
