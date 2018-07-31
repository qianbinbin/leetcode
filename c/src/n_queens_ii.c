#include "n_queens_ii.h"

#include <stdbool.h>
#include <stdlib.h>

static void n_queens_dfs(int n, int row, bool *columns, bool *main_diagonal, bool *anti_diagonal, int *count) {
    if (row == n) {
        ++(*count);
        return;
    }
    for (int col = 0; col < n; ++col) {
        const int main = n - 1 - row + col, anti = row + col;
        if (columns[col] || main_diagonal[main] || anti_diagonal[anti]) continue;
        columns[col] = true;
        main_diagonal[main] = true;
        anti_diagonal[anti] = true;

        n_queens_dfs(n, row + 1, columns, main_diagonal, anti_diagonal, count);

        columns[col] = false;
        main_diagonal[main] = false;
        anti_diagonal[anti] = false;
    }
}

int totalNQueens_52_1(int n) {
    if (n < 1) return -1;

    bool *columns = (bool *) calloc(n, sizeof(bool));
    bool *main_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));
    bool *anti_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));

    int ret = 0;

    n_queens_dfs(n, 0, columns, main_diagonal, anti_diagonal, &ret);

    free(columns);
    free(main_diagonal);
    free(anti_diagonal);
    return ret;
}
