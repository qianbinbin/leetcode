#include "surrounded_regions.h"

#include <stdbool.h>
#include <stdlib.h>

static void mark_dfs(char **board, int i, int j, int row, int col) {
    if (board[i][j] == 'O') {
        board[i][j] = 'M';
        if (i > 0)
            mark_dfs(board, i - 1, j, row, col);
        if (i < row - 1)
            mark_dfs(board, i + 1, j, row, col);
        if (j > 0)
            mark_dfs(board, i, j - 1, row, col);
        if (j < col - 1)
            mark_dfs(board, i, j + 1, row, col);
    }
}

void solve_130_1(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize < 1 || boardColSize < 1) return;

    for (int i = 0; i < boardRowSize; ++i) {
        mark_dfs(board, i, 0, boardRowSize, boardColSize);
        if (boardColSize > 1)
            mark_dfs(board, i, boardColSize - 1, boardRowSize, boardColSize);
    }
    for (int j = 1; j < boardColSize - 1; ++j) {
        mark_dfs(board, 0, j, boardRowSize, boardColSize);
        if (boardRowSize > 1)
            mark_dfs(board, boardRowSize - 1, j, boardRowSize, boardColSize);
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'M')
                board[i][j] = 'O';
        }
    }
}
