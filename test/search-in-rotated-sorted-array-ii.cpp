#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <search-in-rotated-sorted-array-ii.h>
}

TEST(leetcode_81, empty) {
    int nums[] = {};
    print_array(nums, 0);
    EXPECT_EQ(search_81(nums, 0, 0), false);
}

TEST(leetcode_81, normal) {
    int nums[] = {6, 7, 9, 0, 0, 2, 2, 4, 5, 6};
    print_array(nums, 10);
    EXPECT_EQ(search_81(nums, 10, 6), true);
    EXPECT_EQ(search_81(nums, 10, 1), false);
}
