#include <gtest/gtest.h>

extern "C" {
#include "median_of_two_sorted_arrays.h"
}

TEST(median_of_two_sorted_arrays_test, findMedianSortedArrays_4_1) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4_1(nums1, 2, nums2, 1), 2);
    int nums3[] = {1, 2};
    int nums4[] = {3, 4};
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4_1(nums3, 2, nums4, 2), 2.5);
}

TEST(median_of_two_sorted_arrays_test, findMedianSortedArrays_4_1_empty) {
    int nums1[] = {};
    int nums2[] = {1};
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4_1(nums1, 0, nums2, 1), 1);
}
