#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "longest_consecutive_sequence.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(longest_consecutive_sequence_test, longestConsecutive_128_1) {
    int nums1[] = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(4, longestConsecutive_128_1(nums1, ARR_SIZE(nums1)));

    int nums2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(9, longestConsecutive_128_1(nums2, ARR_SIZE(nums2)));
}

TEST(longest_consecutive_sequence_test, longestConsecutive_128_2) {
    int nums1[] = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(4, longestConsecutive_128_2(nums1, ARR_SIZE(nums1)));

    int nums2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    EXPECT_EQ(9, longestConsecutive_128_2(nums2, ARR_SIZE(nums2)));
}
