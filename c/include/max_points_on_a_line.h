/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 * Example 1:
 *
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o
 * +------------->
 * 0  1  2  3  4
 *
 * Example 2:
 *
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 */

#ifndef LEETCODE_MAX_POINTS_ON_A_LINE_H
#define LEETCODE_MAX_POINTS_ON_A_LINE_H

#include "common.h"

int maxPoints_149_1(struct Point *points, int pointsSize);

#endif //LEETCODE_MAX_POINTS_ON_A_LINE_H
