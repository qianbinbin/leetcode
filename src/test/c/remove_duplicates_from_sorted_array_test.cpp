#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <remove_duplicates_from_sorted_array.h>
}

TEST(leetcode_26, empty) {
    int nums[] = {};
    array_print(nums, 0);
    EXPECT_EQ(removeDuplicates_26(nums, 0), 0);
}

TEST(leetcode_26, normal) {
    int nums[] = {0, 1, 1, 2, 5, 5, 5, 10, 10};
    array_print(nums, 9);
    int size = removeDuplicates_26(nums, 9);
    EXPECT_EQ(size, 5);
    array_print(nums, size);
}
