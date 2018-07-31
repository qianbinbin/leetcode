#include <gtest/gtest.h>

extern "C" {
#include "max_points_on_a_line.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

typedef struct Point point;

static point point_create(int x, int y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

TEST(max_points_on_a_line_test, maxPoints_149_1) {
    point points1[] = {
            point_create(1, 1),
            point_create(2, 2),
            point_create(3, 3)
    };
    EXPECT_EQ(maxPoints_149_1(points1, ARR_SIZE(points1)), 3);

    point points2[] = {
            point_create(1, 1),
            point_create(3, 2),
            point_create(5, 3),
            point_create(4, 1),
            point_create(2, 3),
            point_create(1, 4)
    };
    EXPECT_EQ(maxPoints_149_1(points2, ARR_SIZE(points2)), 4);
}
