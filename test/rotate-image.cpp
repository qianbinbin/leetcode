#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <rotate-image.h>
}

TEST(leetcode_48, normal) {
    int **matrix = (int **) malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; ++i) {
        int *nums = (int *) malloc(3 * sizeof(int));
        nums[0] = 3 * i + 1;
        nums[1] = 3 * i + 2;
        nums[2] = 3 * i + 3;
        matrix[i] = nums;
    }
    for (int i = 0; i < 3; ++i) {
        array_print(matrix[i], 3);
    }
    printf("\n");

    int n = 3;
    rotate_48(matrix, n, &n);
    for (int i = 0; i < 3; ++i) {
        array_print(matrix[i], 3);
        free(matrix[i]);
    }
    free(matrix);
}
