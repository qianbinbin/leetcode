#include <gtest/gtest.h>

extern "C" {
#include <largest-rectangle-in-histogram.h>
}

TEST(leetcode_84, normal) {
    int nums[] = {2, 1, 5, 6, 2, 3};
    EXPECT_EQ(largestRectangleArea_84(nums, 6), 10);
    int nums1[] = {2, 1, 2};
    EXPECT_EQ(largestRectangleArea_84(nums1, 3), 3);
    int nums2[] = {1, 3, 2, 5, 6, 1};
    EXPECT_EQ(largestRectangleArea_84(nums2, 6), 10);
}