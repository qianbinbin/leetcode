#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <pascals_triangle.h>
}

TEST(leetcode_118, normal) {
    int *col_sizes = NULL;
    int **triangle = generate_118(5, &col_sizes);
    for (int i = 0; i < 5; ++i) {
        array_print(triangle[i], col_sizes[i]);
        free(triangle[i]);
    }
    free(col_sizes);
    free(triangle);
}
