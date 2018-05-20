#include <gtest/gtest.h>

extern "C" {
#include "two_sum.h"
}

TEST(two_sum_test, twoSum_1_1) {
    int nums[] = {2, 7, 11, 15};
    int *result = twoSum_1_1(nums, 4, 9);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 1);
    free(result);
}
