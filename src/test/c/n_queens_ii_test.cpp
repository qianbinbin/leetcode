#include <gtest/gtest.h>

extern "C" {
#include "n_queens_ii.h"
}

TEST(n_queens_ii_test, totalNQueens_52_1) {
    EXPECT_EQ(totalNQueens_52_1(4), 2);
}
