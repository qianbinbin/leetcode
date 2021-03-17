#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "remove_duplicates_from_sorted_array.h"
}

TEST(remove_duplicates_from_sorted_array_test, removeDuplicates_26_1) {
    int nums1[] = {1, 1, 2}, numsSize1 = 3;
    std::vector<int> const expected1{1, 2};
    int const size1 = removeDuplicates_26_1(nums1, numsSize1);
    ASSERT_EQ(expected1.size(), size1);
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + size1));

    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, numsSize2 = 10;
    std::vector<int> const expected2{0, 1, 2, 3, 4};
    int const size2 = removeDuplicates_26_1(nums2, numsSize2);
    ASSERT_EQ(expected2.size(), size2);
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + size2));
}
