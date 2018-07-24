#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "longest_consecutive_sequence.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(longest_consecutive_sequence_test, longestConsecutive_128_1) {
    int nums[] = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(longestConsecutive_128_1(nums, ARR_SIZE(nums)), 4);
}

TEST(longest_consecutive_sequence_test, longestConsecutive_128_2) {
    int nums[] = {100, 4, 200, 1, 3, 2};
    EXPECT_EQ(longestConsecutive_128_2(nums, ARR_SIZE(nums)), 4);
}
