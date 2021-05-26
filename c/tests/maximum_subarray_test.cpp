#include <gtest/gtest.h>

extern "C" {
#include "maximum_subarray.h"
}

TEST(maximum_subarray, maxSubArray_53_1) {
    int nums1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int const numsSize1 = 9;
    int const expected1 = 6;
    EXPECT_EQ(expected1, maxSubArray_53_1(nums1, numsSize1));

    int nums2[] = {1};
    int const numsSize2 = 1;
    int const expected2 = 1;
    EXPECT_EQ(expected2, maxSubArray_53_1(nums2, numsSize2));

    int nums3[] = {5, 4, -1, 7, 8};
    int const numsSize3 = 5;
    int const expected3 = 23;
    EXPECT_EQ(expected3, maxSubArray_53_1(nums3, numsSize3));
}
