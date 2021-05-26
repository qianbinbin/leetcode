// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//
//
// Example 1:
//
// https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
//
// https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//
// Constraints:
//
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#ifndef LEETCODECPP_SPIRALMATRIX_H
#define LEETCODECPP_SPIRALMATRIX_H

#include <vector>

namespace lcpp {

class Solution54_1 {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);
};

} // namespace lcpp

#endif // LEETCODECPP_SPIRALMATRIX_H
