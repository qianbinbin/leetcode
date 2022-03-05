#include <gtest/gtest.h>

extern "C" {
#include "surrounded_regions.h"
}

TEST(surrounded_regions_test, solve_130_1) {
    char board1[][4] = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };
    char *b1[] = {board1[0], board1[1], board1[2], board1[3]};
    int const boardSize1 = 4;
    int boardColSize1[] = {4, 4, 4, 4};
    std::vector<std::vector<char>> const expected1{{'X', 'X', 'X', 'X'},
                                                   {'X', 'X', 'X', 'X'},
                                                   {'X', 'X', 'X', 'X'},
                                                   {'X', 'O', 'X', 'X'}};
    solve_130_1(b1, boardSize1, boardColSize1);
    for (int i = 0; i < boardSize1; ++i) {
        EXPECT_EQ(expected1[i],
                  std::vector<char>(b1[i], b1[i] + boardColSize1[i]));
    }

    char board2[][1] = {{'X'}};
    char *b2[] = {board2[0]};
    int const boardSize2 = 1;
    int boardColSize2[] = {1};
    std::vector<std::vector<char>> const expected2{{'X'}};
    solve_130_1(b2, boardSize2, boardColSize2);
    for (int i = 0; i < boardSize2; ++i) {
        EXPECT_EQ(expected2[i],
                  std::vector<char>(b2[i], b2[i] + boardColSize2[i]));
    }
}
