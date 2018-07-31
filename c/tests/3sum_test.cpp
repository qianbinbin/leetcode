#include <gtest/gtest.h>

extern "C" {
#include "3sum.h"
#include "common.h"
}

TEST(three_sum_test, threeSum_15_1) {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = 0;
    int **triplets = threeSum_15_1(nums, 6, &size);
    for (int i = 0; i < size; ++i) {
        array_print(triplets[i], 3);
        free(triplets[i]);
    }
    free(triplets);
}
