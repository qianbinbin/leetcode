#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "remove_duplicates_from_sorted_array_ii.h"
}

TEST(remove_duplicates_from_sorted_array_ii_test, removeDuplicates_80_1) {
    int nums1[] = {1, 1, 1, 2, 2, 3};
    array_print(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int size1 = removeDuplicates_80_1(nums1, sizeof(nums1) / sizeof(nums1[0]));
    array_print(nums1, size1);

    int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    array_print(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int size2 = removeDuplicates_80_1(nums2, sizeof(nums2) / sizeof(nums2[0]));
    array_print(nums2, size2);
}
