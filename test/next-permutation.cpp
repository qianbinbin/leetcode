#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <next-permutation.h>
}

TEST(leetcode_31, normal) {
    int nums[] = {1, 2, 3};
    print_array(nums, 3);
    for (int i = 0; i < 5; ++i) {
        nextPermutation_31(nums, 3);
        print_array(nums, 3);
    }
}

TEST(leetcode_31, duplicates) {
    int nums[] = {1, 1, 5};
    print_array(nums, 3);
    nextPermutation_31(nums, 3);
    print_array(nums, 3);
    nextPermutation_31(nums, 3);
    print_array(nums, 3);
}
