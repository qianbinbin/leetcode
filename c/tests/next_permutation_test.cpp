#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "next_permutation.h"
}

TEST(next_permutation_test, nextPermutation_31_1) {
    int nums1[] = {1, 2, 3};
    array_print(nums1, 3);
    nextPermutation_31_1(nums1, 3);
    array_print(nums1, 3);

    int nums2[] = {3, 2, 1};
    array_print(nums2, 3);
    nextPermutation_31_1(nums2, 3);
    array_print(nums2, 3);

    int nums3[] = {1, 1, 5};
    array_print(nums3, 3);
    nextPermutation_31_1(nums3, 3);
    array_print(nums3, 3);
}
