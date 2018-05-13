#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <pascals-triangle-ii.h>
}

TEST(leetcode_119, normal) {
    int size = 0;
    int *row = getRow_119(4, &size);
    array_print(row, size);
    free(row);
}
