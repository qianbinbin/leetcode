#include <gtest/gtest.h>

extern "C" {
#include "single_number.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(single_number_test, singleNumber_136_1) {
    int nums1[] = {2, 2, 1};
    EXPECT_EQ(1, singleNumber_136_1(nums1, ARR_SIZE(nums1)));

    int nums2[] = {4, 1, 2, 1, 2};
    EXPECT_EQ(4, singleNumber_136_1(nums2, ARR_SIZE(nums2)));

    int nums3[] = {1};
    EXPECT_EQ(1, singleNumber_136_1(nums3, ARR_SIZE(nums3)));
}
