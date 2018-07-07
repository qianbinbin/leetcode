#include <gtest/gtest.h>

extern "C" {
#include "search_in_rotated_sorted_array_ii.h"
}

TEST(search_in_rotated_sorted_array_ii_test, search_81_1) {
    int nums1[] = {2, 5, 6, 0, 0, 1, 2};
    EXPECT_TRUE(search_81_1(nums1, sizeof(nums1) / sizeof(nums1[0]), 0));
    EXPECT_FALSE(search_81_1(nums1, sizeof(nums1) / sizeof(nums1[0]), 3));
}
