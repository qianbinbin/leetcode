#include "valid_sudoku.h"

#include <stddef.h>

bool isValidSudoku_36_1(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize != 9 || boardColSize != 9) return false;

    bool row_used[9][9] = {0};
    bool col_used[9][9] = {0};
    bool block_used[9][9] = {0};
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') continue;
            const int num = board[row][col] - '1';
            const int block = row / 3 * 3 + col / 3;
            if (row_used[row][num] || col_used[col][num] || block_used[block][num])
                return false;
            row_used[row][num] = true;
            col_used[col][num] = true;
            block_used[block][num] = true;
        }
    }
    return true;
}
