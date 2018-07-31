#include <gtest/gtest.h>

extern "C" {
#include "word_search.h"
}

TEST(word_search_test, exist_79_1) {
    char chars[][4] = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    char *board[] = {chars[0], chars[1], chars[2]};
    EXPECT_TRUE(exist_79_1(board, 3, 4, "ABCCED"));
    EXPECT_TRUE(exist_79_1(board, 3, 4, "SEE"));
    EXPECT_FALSE(exist_79_1(board, 3, 4, "ABCB"));
}
