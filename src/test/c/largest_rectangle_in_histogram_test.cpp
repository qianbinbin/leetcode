#include <gtest/gtest.h>

extern "C" {
#include "largest_rectangle_in_histogram.h"
}

TEST(largest_rectangle_in_histogram_test, largestRectangleArea_84_1) {
    int heights[] = {2, 1, 5, 6, 2, 3};
    EXPECT_EQ(largestRectangleArea_84_1(heights, sizeof(heights) / sizeof(heights[0])), 10);
}