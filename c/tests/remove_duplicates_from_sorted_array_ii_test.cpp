#include <gtest/gtest.h>

extern "C" {
#include "remove_duplicates_from_sorted_array_ii.h"
}

TEST(remove_duplicates_from_sorted_array_ii_test, removeDuplicates_80_1) {
    int nums1[] = {1, 1, 1, 2, 2, 3};
    std::vector<int> expected1{1, 1, 2, 2, 3};
    int size1 = removeDuplicates_80_1(nums1, sizeof(nums1) / sizeof(nums1[0]));
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + size1));

    int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::vector<int> expected2{0, 0, 1, 1, 2, 3, 3};
    int size2 = removeDuplicates_80_1(nums2, sizeof(nums2) / sizeof(nums2[0]));
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + size2));
}
