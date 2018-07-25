#include <gtest/gtest.h>

extern "C" {
#include "surrounded_regions.h"
}

TEST(surrounded_regions_test, solve_130_1) {
    char board[][5] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };
    char *p_board[] = {board[0], board[1], board[2], board[3]};
    solve_130_1(p_board, 4, 4);
    for (int i = 0; i < 4; ++i) puts(p_board[i]);
}
