#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <plus_one.h>
}

TEST(leetcode_66, normal) {
    int digits[] = {9, 9, 9, 9};
    array_print(digits, 4);
    int size = 0;
    int *result = plusOne_66(digits, 4, &size);
    EXPECT_EQ(size, 5);
    array_print(result, size);
    free(result);
}
