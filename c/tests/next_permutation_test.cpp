#include <gtest/gtest.h>

extern "C" {
#include "next_permutation.h"
}

TEST(next_permutation_test, nextPermutation_31_1) {
    int nums1[] = {1, 2, 3};
    int const numsSize1 = 3;
    std::vector<int> expected1{1, 3, 2};
    nextPermutation_31_1(nums1, numsSize1);
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + numsSize1));

    int nums2[] = {3, 2, 1};
    int const numsSize2 = 3;
    std::vector<int> expected2{1, 2, 3};
    nextPermutation_31_1(nums2, numsSize2);
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + numsSize2));

    int nums3[] = {1, 1, 5};
    int const numsSize3 = 3;
    std::vector<int> expected3{1, 5, 1};
    nextPermutation_31_1(nums3, numsSize3);
    EXPECT_EQ(expected3, std::vector<int>(nums3, nums3 + numsSize3));

    int nums4[] = {1};
    int const numsSize4 = 1;
    std::vector<int> expected4{1};
    nextPermutation_31_1(nums4, numsSize4);
    EXPECT_EQ(expected4, std::vector<int>(nums4, nums4 + numsSize4));
}
