#include <gtest/gtest.h>

extern "C" {
#include "n_queens.h"
}

TEST(n_queens_test, solveNQueens_51_1) {
    int const n1 = 4;
    int returnSize1 = 0, *returnColumnSizes1 = NULL;
    std::vector<std::vector<std::string>> const expected1{
            {".Q..", "...Q", "Q...", "..Q."},
            {"..Q.", "Q...", "...Q", ".Q.."}
    };
    char ***actual1 = solveNQueens_51_1(n1, &returnSize1, &returnColumnSizes1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        ASSERT_EQ(expected1[i].size(), returnColumnSizes1[i]);
        for (int j = 0; j < returnColumnSizes1[i]; ++j) {
            EXPECT_EQ(expected1[i][j], actual1[i][j]);
            free(actual1[i][j]);
        }
        free(actual1[i]);
    }
    free(actual1);
    free(returnColumnSizes1);
}
