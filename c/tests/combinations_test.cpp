#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "combinations.h"
}

TEST(combinations_test, combine_77_1) {
    int size = 0;
    int *col_sizes = NULL;
    int **combinations = combine_77_1(4, 2, &col_sizes, &size);
    for (int i = 0; i < size; ++i) {
        array_print(combinations[i], col_sizes[i]);
        free(combinations[i]);
    }
    free(combinations);
    free(col_sizes);
}
