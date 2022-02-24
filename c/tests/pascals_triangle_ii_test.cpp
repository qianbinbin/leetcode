#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "pascals_triangle_ii.h"
}

TEST(pascals_triangle_ii_test, getRow_119_1) {
    int const rowIndex1 = 3;
    int returnSize1 = 0;
    std::vector<int> const expected1{1, 3, 3, 1};
    int *actual1 = getRow_119_1(rowIndex1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    int const rowIndex2 = 0;
    int returnSize2 = 0;
    std::vector<int> const expected2{1};
    int *actual2 = getRow_119_1(rowIndex2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);

    int const rowIndex3 = 1;
    int returnSize3 = 0;
    std::vector<int> const expected3{1, 1};
    int *actual3 = getRow_119_1(rowIndex3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
}
