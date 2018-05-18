#include <gtest/gtest.h>

extern "C" {
#include <word_search.h>
}

TEST(leetcode_79, normal) {
    char *board[3];
    for (int i = 0; i < 3; ++i)
        board[i] = (char *) malloc(5);
    strcpy(board[0], "ABCE");
    strcpy(board[1], "SFCS");
    strcpy(board[2], "ADEE");
    EXPECT_TRUE(exist_79(board, 3, 4, "ABCCED"));
    EXPECT_TRUE(exist_79(board, 3, 4, "SEE"));
    EXPECT_FALSE(exist_79(board, 3, 4, "ABCB"));
    for (int i = 0; i < 3; ++i)
        free(board[i]);
}
