#include <gtest/gtest.h>

extern "C" {
#include "find_first_and_last_position_of_element_in_sorted_array.h"
}

TEST(find_first_and_last_position_of_element_in_sorted_array_test,
     searchRange_34_1) {
    int nums1[] = {5, 7, 7, 8, 8, 10}, numsSize1 = 6, target1 = 8;
    int returnSize1 = 0;
    std::vector<int> expected1{3, 4};
    int *actual1 = searchRange_34_1(nums1, numsSize1, target1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    int nums2[] = {5, 7, 7, 8, 8, 10}, numsSize2 = 6, target2 = 6;
    int returnSize2 = 0;
    std::vector<int> expected2{-1, -1};
    int *actual2 = searchRange_34_1(nums2, numsSize2, target2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);

    int nums3[] = {}, numsSize3 = 0, target3 = 0;
    int returnSize3 = 0;
    std::vector<int> expected3{-1, -1};
    int *actual3 = searchRange_34_1(nums3, numsSize3, target3, &returnSize3);
    ASSERT_EQ(expected3.size(), returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
}
