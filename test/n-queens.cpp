#include <gtest/gtest.h>

extern "C" {
#include <n-queens.h>
}

TEST(leetcode_51, normal) {
    const int n = 4;
    int size = 0;
    char ***boards = solveNQueens_51(n, &size);
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
