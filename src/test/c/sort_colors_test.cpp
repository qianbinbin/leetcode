#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "sort_colors.h"
}

TEST(sort_colors_test, sortColors_75_1) {
    int nums[] = {0, 2, 1, 1, 2, 0};
    array_print(nums, 6);
    sortColors_75_1(nums, 6);
    array_print(nums, 6);
}

TEST(sort_colors_test, sortColors_75_2) {
    int nums[] = {0, 2, 1, 1, 2, 0};
    array_print(nums, 6);
    sortColors_75_2(nums, 6);
    array_print(nums, 6);
}
