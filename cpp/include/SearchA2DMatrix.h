// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the
// previous row.
//
// Example 1:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
// Example 2:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

#ifndef LEETCODECPP_SEARCHA2DMATRIX_H
#define LEETCODECPP_SEARCHA2DMATRIX_H

#include <vector>

namespace lcpp {

class Solution74_1 {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target);
};

}

#endif //LEETCODECPP_SEARCHA2DMATRIX_H
