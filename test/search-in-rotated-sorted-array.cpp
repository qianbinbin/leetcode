#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <search-in-rotated-sorted-array.h>
}

TEST(leetcode_33, empty) {
    int nums[] = {};
    print_array(nums, 0);
    EXPECT_EQ(search_33(nums, 0, 0), -1);
}

TEST(leetcode_33, normal) {
    int nums[] = {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
    print_array(nums, 10);
    EXPECT_EQ(search_33(nums, 10, 5), 8);
    EXPECT_EQ(search_33(nums, 10, 10), -1);
}
