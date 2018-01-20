#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <remove-duplicates-from-sorted-array.h>
}

TEST(leetcode_26, empty) {
    int nums[] = {};
    print_array(nums, 0);
    EXPECT_EQ(removeDuplicates_26(nums, 0), 0);
}

TEST(leetcode_26, normal) {
    int nums[] = {0, 1, 1, 2, 5, 5, 5, 10, 10};
    print_array(nums, 9);
    int size = removeDuplicates_26(nums, 9);
    EXPECT_EQ(size, 5);
    print_array(nums, size);
}
