#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <first_missing_positive.h>
}

TEST(leetcode_41, normal_1) {
    int nums[] = {1, 1};
    array_print(nums, 2);
    EXPECT_EQ(firstMissingPositive_41(nums, 2), 2);
    array_print(nums, 2);
}

TEST(leetcode_41, normal_2) {
    int nums[] = {3, 4, -1, 1};
    array_print(nums, 4);
    EXPECT_EQ(firstMissingPositive_41(nums, 4), 2);
    array_print(nums, 4);
}
