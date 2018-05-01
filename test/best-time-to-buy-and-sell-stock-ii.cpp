#include <gtest/gtest.h>

extern "C" {
#include <best-time-to-buy-and-sell-stock-ii.h>
}

TEST(leetcode_122_1, normal) {
    int nums1[] = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(maxProfit_122_1(nums1, 6), 7);
    int nums2[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit_122_1(nums2, 5), 4);
    int nums3[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit_122_1(nums3, 5), 0);
}
