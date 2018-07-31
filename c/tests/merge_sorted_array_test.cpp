#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "merge_sorted_array.h"
}

TEST(merge_sorted_array_test, merge_88_1) {
    int nums1[6] = {1, 2, 3};
    array_print(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int nums2[] = {2, 5, 6};
    array_print(nums2, sizeof(nums2) / sizeof(nums2[0]));
    merge_88_1(nums1, 3, nums2, 3);
    array_print(nums1, sizeof(nums1) / sizeof(nums1[0]));
}
