#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <combination-sum-ii.h>
}

TEST(leetcode_40, normal) {
    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    int size = 0;
    int *col_sizes = NULL;
    int **combinations = combinationSum2_40(nums, 7, 8, &col_sizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(combinations[i], col_sizes[i]);
        free(combinations[i]);
    }
    free(combinations);
    free(col_sizes);
}
