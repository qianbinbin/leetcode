#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <sort_colors.h>
}

TEST(leetcode_75, normal) {
    int nums[] = {0, 2, 1, 1, 2, 0};
    array_print(nums, 6);
    sortColors_75(nums, 6);
    array_print(nums, 6);
}
