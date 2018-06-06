#include <gtest/gtest.h>

extern "C" {
#include "sudoku_solver.h"
}

TEST(sudoku_solver, solveSudoku_37_1) {
    char *board[9];
    for (int i = 0; i < 9; ++i)
        board[i] = (char *) malloc(10);

    strcpy(board[0], "53..7....");
    strcpy(board[1], "6..195...");
    strcpy(board[2], ".98....6.");
    strcpy(board[3], "8...6...3");
    strcpy(board[4], "4..8.3..1");
    strcpy(board[5], "7...2...6");
    strcpy(board[6], ".6....28.");
    strcpy(board[7], "...419..5");
    strcpy(board[8], "....8..79");
    for (int i = 0; i < 9; ++i)
        puts(board[i]);

    solveSudoku_37_1(board, 9, 9);
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        puts(board[i]);
        free(board[i]);
    }
}
