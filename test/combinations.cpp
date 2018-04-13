#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <combinations.h>
}

TEST(leetcode_77, normal) {
    int size = 0;
    int *col_sizes = NULL;
    int **combinations = combine_77(20, 16, &col_sizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(combinations[i], col_sizes[i]);
        free(combinations[i]);
    }
    free(combinations);
    free(col_sizes);
}
