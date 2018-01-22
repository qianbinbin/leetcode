#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <median-of-two-sorted-arrays.h>
}

TEST(leetcode_4, empty) {
    int nums1[] = {1, 2, 3, 4};
    print_array(nums1, 4);
    int nums2[] = {};
    print_array(nums2, 0);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums1, 4, nums2, 0), 2.5);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums2, 0, nums1, 4), 2.5);
}

TEST(leetcode_4, normal) {
    int nums1[] = {5, 6, 7, 8, 9};
    print_array(nums1, 5);
    int nums2[] = {1, 2, 3, 4, 5, 6};
    print_array(nums2, 6);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums1, 5, nums2, 6), 5);
}
