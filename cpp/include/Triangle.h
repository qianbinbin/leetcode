// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n
// is the total number of rows in the triangle.

#ifndef LEETCODECPP_TRIANGLE_H
#define LEETCODECPP_TRIANGLE_H

#include <vector>

namespace lcpp {

class Solution120_1 {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle);
};

} // namespace lcpp

#endif // LEETCODECPP_TRIANGLE_H
