#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <gray_code.h>
}

TEST(leetcode_89, normal) {
    int size = 0;
    int *result = grayCode_89(3, &size);
    array_print(result, size);
    free(result);
}
