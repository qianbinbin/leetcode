#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <combination_sum.h>
}

TEST(leetcode_39, normal) {
    int nums[] = {2, 3, 6, 7};
    int size = 0;
    int *col_sizes = NULL;
    int **combinations = combinationSum_39(nums, 4, 7, &col_sizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(combinations[i], col_sizes[i]);
        free(combinations[i]);
    }
    free(combinations);
    free(col_sizes);
}
