#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "pascals_triangle.h"
}

TEST(pascals_triangle_test, generate_118_1) {
    int *col_sizes = NULL;
    int **triangle = generate_118_1(5, &col_sizes);
    for (int i = 0; i < 5; ++i) {
        array_print(triangle[i], col_sizes[i]);
        free(triangle[i]);
    }
    free(col_sizes);
    free(triangle);
}
