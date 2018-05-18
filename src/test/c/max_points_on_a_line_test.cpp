#include <gtest/gtest.h>

extern "C" {
#include <max_points_on_a_line.h>
}

typedef struct Point point;

static point point_create(int x, int y) {
    point p;
    p.x = x;
    p.y = y;
    return p;
}

TEST(leetcode_149, normal_1) {
    point p1 = point_create(1, 1);
    point p2 = point_create(2, 2);
    point p3 = point_create(3, 3);
    point points[] = {p1, p2, p3};
    EXPECT_EQ(maxPoints_149(points, 3), 3);
}

TEST(leetcode_149, normal_2) {
    point p1 = point_create(1, 1);
    point p2 = point_create(3, 2);
    point p3 = point_create(5, 3);
    point p4 = point_create(4, 1);
    point p5 = point_create(2, 3);
    point p6 = point_create(1, 4);
    point points[] = {p1, p2, p3, p4, p5, p6};
    EXPECT_EQ(maxPoints_149(points, 6), 4);
}

TEST(leetcode_149, dupicate) {
    point p1 = point_create(3, 1);
    point p2 = point_create(12, 3);
    point p3 = point_create(3, 1);
    point p4 = point_create(-6, -1);
    point points[] = {p1, p2, p3, p4};
    EXPECT_EQ(maxPoints_149(points, 4), 4);
}
