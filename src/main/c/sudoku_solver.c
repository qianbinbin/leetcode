#include "sudoku_solver.h"

#include <stdbool.h>
#include <stddef.h>

static bool solve_sudoku_dfs(char **board, int row, bool row_used[9][9], bool col_used[9][9], bool block_used[9][9]) {
    for (; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] != '.') continue;
            const int block = row / 3 * 3 + col / 3;
            for (char val = '1'; val <= '9'; ++val) {
                const int index = val - '1';
                if (row_used[index][row] || col_used[index][col] || block_used[index][block]) continue;
                board[row][col] = val;
                row_used[index][row] = true;
                col_used[index][col] = true;
                block_used[index][block] = true;

                if (solve_sudoku_dfs(board, row, row_used, col_used, block_used))
                    return true;

                row_used[index][row] = false;
                col_used[index][col] = false;
                block_used[index][block] = false;
            }
            board[row][col] = '.';
            return false;
        }
    }
    return true;
}

void solveSudoku_37_1(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize != 9 || boardColSize != 9) return;

    bool row_used[9][9] = {0};
    bool col_used[9][9] = {0};
    bool block_used[9][9] = {0};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            const int index = board[i][j] - '1';
            const int block = i / 3 * 3 + j / 3;
            row_used[index][i] = true;
            col_used[index][j] = true;
            block_used[index][block] = true;
        }
    }
    solve_sudoku_dfs(board, 0, row_used, col_used, block_used);
}
