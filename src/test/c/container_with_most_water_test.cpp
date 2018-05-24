#include <gtest/gtest.h>

extern "C" {
#include "container_with_most_water.h"
}

TEST(container_with_most_water_test, maxArea_11_1) {
    int nums[] = {4, 1, 3, 2, 1};
    EXPECT_EQ(maxArea_11_1(nums, 5), 6);
}
