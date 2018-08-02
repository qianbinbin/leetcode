#include <gtest/gtest.h>

extern "C" {
#include "maximum_product_subarray.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int nums1[] = {2, 3, -2, 4};

int expected1 = 6;

int nums2[] = {-2, 0, -1};

int expected2 = 0;

TEST(maximum_product_subarray_test, maxProduct_152_1) {
    EXPECT_EQ(maxProduct_152_1(nums1, ARR_SIZE(nums1)), expected1);
    EXPECT_EQ(maxProduct_152_1(nums2, ARR_SIZE(nums2)), expected2);
}
