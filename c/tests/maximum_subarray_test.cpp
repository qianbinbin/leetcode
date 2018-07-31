#include <gtest/gtest.h>

extern "C" {
#include "maximum_subarray.h"
}

TEST(maximum_subarray, maxSubArray_53_1) {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(maxSubArray_53_1(nums, 9), 6);
}

TEST(maximum_subarray, maxSubArray_53_2) {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(maxSubArray_53_2(nums, 9), 6);
}
