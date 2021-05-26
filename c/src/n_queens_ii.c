#include "n_queens_ii.h"

#include <stdbool.h>
#include <stdlib.h>

static void n_queens_dfs(int n, int i, bool *columns, bool *main_diag,
                         bool *anti_diag, int *count) {
    if (i == n) {
        ++(*count);
        return;
    }
    for (int j = 0, d, a; j < n; ++j) {
        d = n - 1 + i - j;
        a = i + j;
        if (columns[j] || main_diag[d] || anti_diag[a])
            continue;
        columns[j] = true;
        main_diag[d] = true;
        anti_diag[a] = true;

        n_queens_dfs(n, i + 1, columns, main_diag, anti_diag, count);

        columns[j] = false;
        main_diag[d] = false;
        anti_diag[a] = false;
    }
}

int totalNQueens_52_1(int n) {
    bool *columns = (bool *) calloc(n, sizeof(bool));
    bool *main_diag = (bool *) calloc(2 * n - 1, sizeof(bool));
    bool *anti_diag = (bool *) calloc(2 * n - 1, sizeof(bool));

    int ret = 0;

    n_queens_dfs(n, 0, columns, main_diag, anti_diag, &ret);

    free(columns);
    free(main_diag);
    free(anti_diag);
    return ret;
}
