#include <gtest/gtest.h>

extern "C" {
#include <palindrome-partitioning.h>
}

TEST(leetcode_131_1, normal) {
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

TEST(leetcode_131_2, normal) {
    int size = 0;
    int *col_sizes = NULL;
    char ***results = partition_131_2("aab", &col_sizes, &size);
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
