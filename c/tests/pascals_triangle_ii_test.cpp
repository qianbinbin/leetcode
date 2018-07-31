#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "pascals_triangle_ii.h"
}

TEST(pascals_triangle_ii_test, getRow_119_1) {
    int size = 0;
    int *row = getRow_119_1(3, &size);
    array_print(row, size);
    free(row);
}
