#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "two_sum.h"
}

TEST(two_sum_test, twoSum_1_1) {
    int nums1[] = {2, 7, 11, 15};
    const int numsSize1 = 4;
    const int target1 = 9;
    const std::vector<int> expected1{0, 1};
    int returnSize1 = 0;
    int *actual1 = twoSum_1_1(nums1, numsSize1, target1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    int nums2[] = {3, 2, 4};
    const int numsSize2 = 3;
    const int target2 = 6;
    const std::vector<int> expected2{1, 2};
    int returnSize2 = 0;
    int *actual2 = twoSum_1_1(nums2, numsSize2, target2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);

    int nums3[] = {3, 3};
    const int numsSize3 = 2;
    const int target3 = 6;
    const std::vector<int> expected3{0, 1};
    int returnSize3 = 0;
    int *actual3 = twoSum_1_1(nums3, numsSize3, target3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
}
