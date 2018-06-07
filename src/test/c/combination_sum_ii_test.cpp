#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "combination_sum_ii.h"
}

TEST(combination_sum_ii_test, combinationSum2_40_1) {
    int candidates1[] = {10, 1, 2, 7, 6, 1, 5};
    int size1 = 0;
    int *col_sizes1 = NULL;
    int **combinations1 = combinationSum2_40_1(candidates1, 7, 8, &col_sizes1, &size1);
    for (int i = 0; i < size1; ++i) {
        array_print(combinations1[i], col_sizes1[i]);
        free(combinations1[i]);
    }
    free(combinations1);
    free(col_sizes1);

    printf("\n");
    int candidates2[] = {2, 5, 2, 1, 2};
    int size2 = 0;
    int *col_sizes2 = NULL;
    int **combinations2 = combinationSum2_40_1(candidates2, 5, 5, &col_sizes2, &size2);
    for (int i = 0; i < size2; ++i) {
        array_print(combinations2[i], col_sizes2[i]);
        free(combinations2[i]);
    }
    free(combinations2);
    free(col_sizes2);
}
