#include <gtest/gtest.h>

extern "C" {
#include "triangle.h"
}

TEST(triangle_test, minimumTotal_120_1) {
    int triangle1[][4] = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    int *t1[] = {triangle1[0], triangle1[1], triangle1[2], triangle1[3]};
    int triangleColSize1[] = {1, 2, 3, 4};
    int const expected1 = 11;
    EXPECT_EQ(expected1, minimumTotal_120_1(t1, sizeof(t1) / sizeof(t1[0]),
                                            triangleColSize1));

    int triangle2[][1] = {
            {-10}
    };
    int *t2[] = {triangle2[0]};
    int triangleColSize2[] = {1};
    int const expected2 = -10;
    EXPECT_EQ(expected2, minimumTotal_120_1(t2, sizeof(t2) / sizeof(t2[0]),
                                            triangleColSize2));
}