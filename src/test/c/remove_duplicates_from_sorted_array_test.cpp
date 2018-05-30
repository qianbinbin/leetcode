#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "remove_duplicates_from_sorted_array.h"
}

TEST(remove_duplicates_from_sorted_array_test, removeDuplicates_26_1) {
    int nums1[] = {1, 1, 2};
    array_print(nums1, 3);
    int size1 = removeDuplicates_26_1(nums1, 3);
    array_print(nums1, size1);

    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    array_print(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int size2 = removeDuplicates_26_1(nums2, sizeof(nums2) / sizeof(nums2[0]));
    array_print(nums2, size2);
}
