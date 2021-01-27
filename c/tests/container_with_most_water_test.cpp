#include <gtest/gtest.h>

extern "C" {
#include "container_with_most_water.h"
}

TEST(container_with_most_water_test, maxArea_11_1) {
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    const int heightSize1 = 9;
    const int expected1 = 49;
    EXPECT_EQ(expected1, maxArea_11_1(height1, heightSize1));

    int height2[] = {1, 1};
    const int heightSize2 = 2;
    const int expected2 = 1;
    EXPECT_EQ(expected2, maxArea_11_1(height2, heightSize2));

    int height3[] = {4, 3, 2, 1, 4};
    const int heightSize3 = 5;
    const int expected3 = 16;
    EXPECT_EQ(expected3, maxArea_11_1(height3, heightSize3));

    int height4[] = {1, 2, 1};
    const int heightSize4 = 3;
    const int expected4 = 2;
    EXPECT_EQ(expected4, maxArea_11_1(height4, heightSize4));
}
