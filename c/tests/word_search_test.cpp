#include <gtest/gtest.h>

extern "C" {
#include "word_search.h"
}

TEST(word_search_test, exist_79_1) {
    char board1[][4] = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    int boardSize1 = 3;
    int boardColSize1[] = {4, 4, 4};
    char *b1[] = {board1[0], board1[1], board1[2]};
    EXPECT_TRUE(exist_79_1(b1, boardSize1, boardColSize1, "ABCCED"));
    EXPECT_TRUE(exist_79_1(b1, boardSize1, boardColSize1, "SEE"));
    EXPECT_FALSE(exist_79_1(b1, boardSize1, boardColSize1, "ABCB"));
}
