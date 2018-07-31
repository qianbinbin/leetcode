#include <gtest/gtest.h>

extern "C" {
#include "palindrome_partitioning.h"
}

TEST(palindrome_partitioning_test, partition_131_1) {
    int size = 0;
    int *col_sizes = NULL;
    char ***results = partition_131_1("aab", &col_sizes, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < col_sizes[i]; ++j) {
            if (j == col_sizes[i] - 1)
                printf("%s\n", results[i][j]);
            else
                printf("%s, ", results[i][j]);
            free(results[i][j]);
        }
        free(results[i]);
    }
    free(col_sizes);
    free(results);
}
