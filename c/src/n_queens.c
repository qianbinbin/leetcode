#include "n_queens.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char **board_create(int n) {
    char **new = (char **) malloc(n * sizeof(char *));
    char *tmp = (char *) malloc((n + 1) * sizeof(char));
    memset(tmp, '.', n);
    tmp[n] = '\0';
    for (int i = 0; i < n; ++i)
        new[i] = strdup(tmp);
    free(tmp);
    return new;
}

static char **board_copy(char **board, int n) {
    char **copy = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i)
        copy[i] = strdup(board[i]);
    return copy;
}

static void board_free(char **board, int n) {
    for (int i = 0; i < n; ++i)
        free(board[i]);
    free(board);
}

static void n_queens_dfs(int n, int i, bool *columns, bool *main_diagonal,
                         bool *anti_diagonal,
                         char ****boards, int *size, int *capacity,
                         char **board) {
    if (i == n) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *boards = (char ***) realloc(*boards, *capacity * sizeof(char **));
        }
        (*boards)[(*size)++] = board_copy(board, n);
        return;
    }
    for (int j = 0, d, a; j < n; ++j) {
        d = n - 1 + i - j;
        a = i + j;
        if (columns[j] || main_diagonal[d] || anti_diagonal[a])
            continue;
        board[i][j] = 'Q';
        columns[j] = true;
        main_diagonal[d] = true;
        anti_diagonal[a] = true;

        n_queens_dfs(n, i + 1, columns, main_diagonal, anti_diagonal, boards,
                     size, capacity, board);

        columns[j] = false;
        main_diagonal[d] = false;
        anti_diagonal[a] = false;
        board[i][j] = '.';
    }
}

char ***solveNQueens_51_1(int n, int *returnSize, int **returnColumnSizes) {
    bool *column = (bool *) calloc(n, sizeof(bool));
    bool *main_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));
    bool *anti_diagonal = (bool *) calloc(2 * n - 1, sizeof(bool));

    int capacity = 16;
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));

    char **board = board_create(n);

    n_queens_dfs(n, 0, column, main_diagonal, anti_diagonal, &ret, returnSize,
                 &capacity, board);

    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));
    // dumb argument
    *returnColumnSizes = (int *) malloc((*returnSize) * sizeof(int));
    for (int i = *returnSize - 1; i >= 0; --i) (*returnColumnSizes)[i] = n;

    board_free(board, n);
    free(column);
    free(main_diagonal);
    free(anti_diagonal);
    return ret;
}
