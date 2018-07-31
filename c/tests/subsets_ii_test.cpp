#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "subsets_ii.h"
}

TEST(subsets_ii_test, subsetsWithDup_90_1) {
    int nums[] = {1, 2, 2};
    int size = 0;
    int *cols = NULL;
    int **subsets = subsetsWithDup_90_1(nums, 3, &cols, &size);
    for (int i = 0; i < size; ++i) {
        array_print(subsets[i], cols[i]);
        free(subsets[i]);
    }
    free(cols);
    free(subsets);
}
