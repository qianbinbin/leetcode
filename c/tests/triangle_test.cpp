#include <gtest/gtest.h>

extern "C" {
#include "triangle.h"
}

TEST(triangle_test, minimumTotal_120_1) {
    int triangle[][4] = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    int *p_triangle[] = {triangle[0], triangle[1], triangle[2], triangle[3]};
    int cols[] = {1, 2, 3, 4};
    EXPECT_EQ(minimumTotal_120_1(p_triangle, 4, cols), 11);
}