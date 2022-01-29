#include <gtest/gtest.h>

extern "C" {
#include "gray_code.h"
}

TEST(leetcode_89_1, normal) {
    int n1 = 2;
    int returnSize1 = 0;
    std::vector<int> expected1{0, 1, 3, 2};
    int *actual1 = grayCode_89_1(n1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    int n2 = 1;
    int returnSize2 = 0;
    std::vector<int> expected2{0, 1};
    int *actual2 = grayCode_89_1(n2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
}

TEST(leetcode_89_2, normal) {
    int n1 = 2;
    int returnSize1 = 0;
    std::vector<int> expected1{0, 1, 3, 2};
    int *actual1 = grayCode_89_2(n1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);

    int n2 = 1;
    int returnSize2 = 0;
    std::vector<int> expected2{0, 1};
    int *actual2 = grayCode_89_2(n2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
}