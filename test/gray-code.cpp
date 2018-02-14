#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <gray-code.h>
}

TEST(leetcode_89, normal) {
    int size = 0;
    int *result = grayCode_89(3, &size);
    print_array(result, size);
    free(result);
}
