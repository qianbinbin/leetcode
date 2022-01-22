#include <gtest/gtest.h>

extern "C" {
#include "sort_colors.h"
}

TEST(sort_colors_test, sortColors_75_1) {
    int nums1[] = {0, 2, 1, 1, 2, 0};
    int const numsSize1 = 6;
    std::vector<int> expected1{0, 0, 1, 1, 2, 2};
    sortColors_75_1(nums1, numsSize1);
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + numsSize1));

    int nums2[] = {2, 0, 1};
    int const numsSize2 = 3;
    std::vector<int> expected2{0, 1, 2};
    sortColors_75_1(nums2, numsSize2);
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + numsSize2));
}

TEST(sort_colors_test, sortColors_75_2) {
    int nums1[] = {0, 2, 1, 1, 2, 0};
    int const numsSize1 = 6;
    std::vector<int> expected1{0, 0, 1, 1, 2, 2};
    sortColors_75_2(nums1, numsSize1);
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + numsSize1));

    int nums2[] = {2, 0, 1};
    int const numsSize2 = 3;
    std::vector<int> expected2{0, 1, 2};
    sortColors_75_2(nums2, numsSize2);
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + numsSize2));
}
