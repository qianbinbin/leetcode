#include <gtest/gtest.h>

extern "C" {
#include "search_in_rotated_sorted_array.h"
}

TEST(search_in_rotated_sorted_array_test, search_33_1) {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(search_33_1(nums, sizeof(nums) / sizeof(nums[0]), 0), 4);
    EXPECT_EQ(search_33_1(nums, sizeof(nums) / sizeof(nums[0]), 3), -1);
}
