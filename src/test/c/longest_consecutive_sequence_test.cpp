#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <longest_consecutive_sequence.h>
}

TEST(leetcode_128_1, empty) {
    int nums[] = {};
    array_print(nums, 0);
    EXPECT_EQ(longestConsecutive_128_1(nums, 0), 0);
}

TEST(leetcode_128_1, normal) {
    int nums[] = {1, 4, 2, 1, 3, 2};
    array_print(nums, 6);
    EXPECT_EQ(longestConsecutive_128_1(nums, 6), 4);
}

TEST(leetcode_128_2, empty) {
    int nums[] = {};
    array_print(nums, 0);
    EXPECT_EQ(longestConsecutive_128_2(nums, 0), 0);
}

TEST(leetcode_128_2, normal) {
    int nums[] = {1, 4, 2, 1, 3, 2};
    array_print(nums, 6);
    EXPECT_EQ(longestConsecutive_128_2(nums, 6), 4);
}
