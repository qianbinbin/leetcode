#include <gtest/gtest.h>

extern "C" {
#include "plus_one.h"
}

TEST(plus_one_test, plusOne_66_1) {
    int digits1[] = {1, 2, 3};
    int const digitsSize1 = 3;
    int returnSize1 = 0;
    int expected1[] = {1, 2, 4};
    int const expectedSize1 = 3;
    int *actual1 = plusOne_66_1(digits1, digitsSize1, &returnSize1);
    ASSERT_EQ(expectedSize1, returnSize1);
    for (int i = 0; i < returnSize1; ++i)
        EXPECT_EQ(expected1[i], actual1[i]);
    free(actual1);

    int digits2[] = {4, 3, 2, 1};
    int const digitsSize2 = 4;
    int returnSize2 = 0;
    int expected2[] = {4, 3, 2, 2};
    int const expectedSize2 = 4;
    int *actual2 = plusOne_66_1(digits2, digitsSize2, &returnSize2);
    ASSERT_EQ(expectedSize2, returnSize2);
    for (int i = 0; i < returnSize2; ++i)
        EXPECT_EQ(expected2[i], actual2[i]);
    free(actual2);

    int digits3[] = {9};
    int const digitsSize3 = 1;
    int returnSize3 = 0;
    int expected3[] = {1, 0};
    int const expectedSize3 = 2;
    int *actual3 = plusOne_66_1(digits3, digitsSize3, &returnSize3);
    ASSERT_EQ(expectedSize3, returnSize3);
    for (int i = 0; i < returnSize3; ++i)
        EXPECT_EQ(expected3[i], actual3[i]);
    free(actual3);
}
