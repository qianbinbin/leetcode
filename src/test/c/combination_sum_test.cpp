#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "combination_sum.h"
}

TEST(combination_sum_test, combinationSum_39_1) {
    int nums1[] = {2, 3, 6, 7};
    int size1 = 0;
    int *col_sizes1 = NULL;
    int **combinations1 = combinationSum_39_1(nums1, 4, 7, &col_sizes1, &size1);
    for (int i = 0; i < size1; ++i) {
        array_print(combinations1[i], col_sizes1[i]);
        free(combinations1[i]);
    }
    free(combinations1);
    free(col_sizes1);

    printf("\n");
    int nums2[] = {2, 3, 5};
    int size2 = 0;
    int *col_sizes2 = NULL;
    int **combinations2 = combinationSum_39_1(nums2, 3, 8, &col_sizes2, &size2);
    for (int i = 0; i < size2; ++i) {
        array_print(combinations2[i], col_sizes2[i]);
        free(combinations2[i]);
    }
    free(combinations2);
    free(col_sizes2);
}
