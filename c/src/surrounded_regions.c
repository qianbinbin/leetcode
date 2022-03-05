#include "surrounded_regions.h"

static void mark_dfs(char **board, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
        return;
    board[i][j] = 'M';
    mark_dfs(board, i - 1, j, m, n);
    mark_dfs(board, i + 1, j, m, n);
    mark_dfs(board, i, j - 1, m, n);
    mark_dfs(board, i, j + 1, m, n);
}

void solve_130_1(char **board, int boardSize, int *boardColSize) {
    int const m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; ++i) {
        mark_dfs(board, i, 0, m, n);
        if (n > 1)
            mark_dfs(board, i, n - 1, m, n);
    }
    for (int j = 1; j < n - 1; ++j) {
        mark_dfs(board, 0, j, m, n);
        if (m > 1)
            mark_dfs(board, m - 1, j, m, n);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'M')
                board[i][j] = 'O';
        }
    }
}
