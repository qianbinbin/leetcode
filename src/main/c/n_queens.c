#include <n_queens.h>
#include <stdbool.h>
#include <stdlib.h>

static char **board_create(int n) {
    char **new = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {
        new[i] = (char *) malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; ++j)
            new[i][j] = '.';
        new[i][n] = '\0';
    }
    return new;
}

static char **board_copy(char **board, int n) {
    char **copy = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {
        copy[i] = (char *) malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; ++j)
            copy[i][j] = board[i][j];
        copy[i][n] = '\0';
    }
    return copy;
}

static void board_free(char **board, int n) {
    for (int i = 0; i < n; ++i)
        free(board[i]);
    free(board);
}

static void n_queens_dfs(int n, int row, bool *columns, bool *main_diagonal, bool *anti_diagonal,
                         char ****boards, int *size, int *capacity, char **path) {
    if (row == n) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *boards = (char ***) realloc(*boards, (*capacity) * sizeof(char **));
        }
        (*boards)[(*size)++] = board_copy(path, n);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (!columns[col] && !main_diagonal[n - 1 - row + col] && !anti_diagonal[row + col]) {
            path[row][col] = 'Q';
            columns[col] = true;
            main_diagonal[n - 1 - row + col] = true;
            anti_diagonal[row + col] = true;

            n_queens_dfs(n, row + 1, columns, main_diagonal, anti_diagonal, boards, size, capacity, path);

            columns[col] = false;
            main_diagonal[n - 1 - row + col] = false;
            anti_diagonal[row + col] = false;
            path[row][col] = '.';
        }
    }
}

char ***solveNQueens_51(int n, int *returnSize) {
    if (n < 1 || returnSize == NULL) return NULL;

    bool *columns = (bool *) calloc(n, sizeof(bool));
    bool *main_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));
    bool *anti_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));

    int capacity = 64;
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));

    char **path = board_create(n);

    n_queens_dfs(n, 0, columns, main_diagonal, anti_diagonal, &ret, returnSize, &capacity, path);

    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));

    board_free(path, n);
    free(columns);
    free(main_diagonal);
    free(anti_diagonal);
    return ret;
}
