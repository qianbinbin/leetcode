#include "sudoku_solver.h"

#include <stdbool.h>

static bool solve_sudoku(char **board, int i, bool row_used[9][9],
                         bool col_used[9][9], bool block_used[9][9]) {
    for (int j, b, n; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (board[i][j] != '.') continue;
            b = i / 3 * 3 + j / 3;
            for (n = 0; n < 9; ++n) {
                if (row_used[n][i] || col_used[n][j] ||
                    block_used[n][b])
                    continue;
                board[i][j] = (char) (n + '1');
                row_used[n][i] = true;
                col_used[n][j] = true;
                block_used[n][b] = true;
                if (solve_sudoku(board, i, row_used, col_used,
                                 block_used))
                    return true;
                row_used[n][i] = false;
                col_used[n][j] = false;
                block_used[n][b] = false;
            }
            board[i][j] = '.';
            return false;
        }
    }
    return true;
}

void solveSudoku_37_1(char **board, int boardSize, int *boardColSize) {
    bool row_used[9][9] = {0};
    bool col_used[9][9] = {0};
    bool block_used[9][9] = {0};
    for (int i = 0, j, b, n; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            b = i / 3 * 3 + j / 3;
            n = board[i][j] - '1';
            row_used[n][i] = true;
            col_used[n][j] = true;
            block_used[n][b] = true;
        }
    }
    solve_sudoku(board, 0, row_used, col_used, block_used);
}
