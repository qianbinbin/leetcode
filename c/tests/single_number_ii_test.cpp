#include <gtest/gtest.h>

extern "C" {
#include "single_number_ii.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(single_number_ii_test, singleNumber_137_1) {
    int nums1[] = {2, 2, 3, 2};
    EXPECT_EQ(3, singleNumber_137_1(nums1, ARR_SIZE(nums1)));

    int nums2[] = {0, 1, 0, 1, 0, 1, 99};
    EXPECT_EQ(99, singleNumber_137_1(nums2, ARR_SIZE(nums2)));
}
