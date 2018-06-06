#include <gtest/gtest.h>

extern "C" {
#include "valid_sudoku.h"
}

TEST(valid_sudoku_test, isValidSudoku_36_1) {
    char *board1[9] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
    };
    EXPECT_TRUE(isValidSudoku_36_1(board1, 9, 9));

    char *board2[9] = {
            "83..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
    };
    EXPECT_FALSE(isValidSudoku_36_1(board2, 9, 9));
}
