#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <merge-sorted-array.h>
}

TEST(leetcode_88_1, empty_1) {
    int nums1[] = {0};
    array_print(nums1, 1);
    int nums2[] = {1};
    array_print(nums2, 1);
    merge_88_1(nums1, 0, nums2, 1);
    array_print(nums1, 1);
}

TEST(leetcode_88_1, empty_2) {
    int nums1[] = {1, 0};
    array_print(nums1, 2);
    int nums2[] = {0};
    array_print(nums2, 1);
    merge_88_1(nums1, 1, nums2, 0);
    array_print(nums1, 1);
}

TEST(leetcode_88_1, normal) {
    int nums1[10] = {1, 3, 5, 7, 9};
    array_print(nums1, 10);
    int nums2[] = {0, 2, 4, 6, 8};
    merge_88_1(nums1, 5, nums2, 5);
    array_print(nums1, 10);
}
