#include <gtest/gtest.h>

extern "C" {
#include "n_queens.h"
}

TEST(n_queens_test, solveNQueens_51_1) {
    const int n = 4;
    int size = 0;
    char ***boards = solveNQueens_51_1(n, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < n; ++j) {
            puts(boards[i][j]);
            free(boards[i][j]);
        }
        free(boards[i]);
        puts("");
    }
    free(boards);
}
