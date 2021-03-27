#include <gtest/gtest.h>

extern "C" {
#include "sudoku_solver.h"
}

TEST(sudoku_solver, solveSudoku_37_1) {
    char *board1[9] = {
            strdup("53..7...."),
            strdup("6..195..."),
            strdup(".98....6."),
            strdup("8...6...3"),
            strdup("4..8.3..1"),
            strdup("7...2...6"),
            strdup(".6....28."),
            strdup("...419..5"),
            strdup("....8..79")
    };
    solveSudoku_37_1(board1, 0, nullptr);
    char const *expected1[9] = {
            "534678912",
            "672195348",
            "198342567",
            "859761423",
            "426853791",
            "713924856",
            "961537284",
            "287419635",
            "345286179"
    };
    EXPECT_EQ(std::vector<std::string>(expected1, expected1 + 9),
              std::vector<std::string>(board1, board1 + 9));
    for (auto &s : board1) free(s);
}
