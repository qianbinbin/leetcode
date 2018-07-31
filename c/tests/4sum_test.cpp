#include <gtest/gtest.h>

extern "C" {
#include "4sum.h"
#include "common.h"
}

TEST(four_sum_test, fourSum_18_1) {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int size = 0;
    int **quadruplets = fourSum_18_1(nums, 6, 0, &size);
    for (int i = 0; i < size; ++i) {
        array_print(quadruplets[i], 4);
        free(quadruplets[i]);
    }
    free(quadruplets);
}
