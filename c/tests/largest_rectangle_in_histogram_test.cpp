#include <gtest/gtest.h>

extern "C" {
#include "largest_rectangle_in_histogram.h"
}

TEST(largest_rectangle_in_histogram_test, largestRectangleArea_84_1) {
    int heights1[] = {2, 1, 5, 6, 2, 3};
    int const expected1 = 10;
    EXPECT_EQ(expected1, largestRectangleArea_84_1(heights1, sizeof(heights1) /
                                                             sizeof(heights1[0])));

    int heights2[] = {2, 4};
    int const expected2 = 4;
    EXPECT_EQ(expected2, largestRectangleArea_84_1(heights2, sizeof(heights2) /
                                                             sizeof(heights2[0])));
}