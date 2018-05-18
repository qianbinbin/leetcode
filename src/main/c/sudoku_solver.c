#include <sudoku_solver.h>
#include <stdbool.h>
#include <stddef.h>

static bool solve_sudoku_dfs(char **board, bool rows[9][9], bool cols[9][9], bool halls[9][9], int row) {
    for (; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                const int hall = row / 3 * 3 + col / 3;
                for (char val = '1'; val <= '9'; ++val) {
                    const int index = val - '1';
                    if (!rows[index][row] && !cols[index][col] && !halls[index][hall]) {
                        rows[index][row] = true;
                        cols[index][col] = true;
                        halls[index][hall] = true;
                        board[row][col] = val;

                        if (solve_sudoku_dfs(board, rows, cols, halls, row))
                            return true;

                        board[row][col] = '.';
                        rows[index][row] = false;
                        cols[index][col] = false;
                        halls[index][hall] = false;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku_37(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize != 9 || boardColSize != 9) return;

    bool rows[9][9] = {0};
    bool cols[9][9] = {0};
    bool halls[9][9] = {0};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                const int index = board[i][j] - '1';
                const int hall = i / 3 * 3 + j / 3;
                rows[index][i] = true;
                cols[index][j] = true;
                halls[index][hall] = true;
            }
        }
    }
    solve_sudoku_dfs(board, rows, cols, halls, 0);
}
