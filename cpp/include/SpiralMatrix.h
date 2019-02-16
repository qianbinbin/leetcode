// Given a matrix of m x n elements (m rows, n columns), return all elements of
// the matrix in spiral order.
//
// Example 1:
//
// Input:
// [
//   [ 1, 2, 3 ],
//   [ 4, 5, 6 ],
//   [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#ifndef LEETCODECPP_SPIRALMATRIX_H
#define LEETCODECPP_SPIRALMATRIX_H

#include <vector>

namespace lcpp {

class Solution54_1 {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);
};

}

#endif //LEETCODECPP_SPIRALMATRIX_H
