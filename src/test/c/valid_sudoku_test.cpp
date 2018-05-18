#include <gtest/gtest.h>

extern "C" {
#include <valid_sudoku.h>
}

TEST(leetcode_36, normal) {
    char *board[9] = {".87654321",
                      "2........",
                      "3........",
                      "4........",
                      "5........",
                      "6........",
                      "7........",
                      "8........",
                      "9........"};
    EXPECT_TRUE(isValidSudoku_36(board, 9, 9));
}
