// Given n points on a 2D plane, find the maximum number of points that lie on
// the same straight line.
//
// Example 1:
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o
// +------------->
// 0  1  2  3  4
//
// Example 2:
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6

#ifndef LEETCODECPP_MAXPOINTSONALINE_H
#define LEETCODECPP_MAXPOINTSONALINE_H

#include "Point.h"
#include <vector>

namespace lcpp {

class Solution149_1 {
public:
  int maxPoints(std::vector<Point> &points);
};

}

#endif //LEETCODECPP_MAXPOINTSONALINE_H
