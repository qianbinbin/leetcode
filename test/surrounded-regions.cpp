#include <gtest/gtest.h>

extern "C" {
#include <surrounded-regions.h>
}

TEST(leetcode_130_1, normal) {
    char *board[4];
    board[0] = (char *) malloc(5);
    strcpy(board[0], "XXXX");
    board[1] = (char *) malloc(5);
    strcpy(board[1], "XOOX");
    board[2] = (char *) malloc(5);
    strcpy(board[2], "XXOX");
    board[3] = (char *) malloc(5);
    strcpy(board[3], "XOXX");
    for (int i = 0; i < 4; ++i) {
        puts(board[i]);
    }

    printf("\n");
    solve_130_1(board, 4, 4);
    for (int i = 0; i < 4; ++i) {
        puts(board[i]);
        free(board[i]);
    }
}

TEST(leetcode_130_2, normal) {
    char *board[4];
    board[0] = (char *) malloc(5);
    strcpy(board[0], "XXXX");
    board[1] = (char *) malloc(5);
    strcpy(board[1], "XOOX");
    board[2] = (char *) malloc(5);
    strcpy(board[2], "XXOX");
    board[3] = (char *) malloc(5);
    strcpy(board[3], "XOXX");
    for (int i = 0; i < 4; ++i) {
        puts(board[i]);
    }

    printf("\n");
    solve_130_2(board, 4, 4);
    for (int i = 0; i < 4; ++i) {
        puts(board[i]);
        free(board[i]);
    }
}
