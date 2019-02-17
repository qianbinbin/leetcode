// Given a positive integer n, generate a square matrix filled with elements
// from 1 to n2 in spiral order.
//
// Example:
//
// Input: 3
// Output:
// [
//   [ 1, 2, 3 ],
//   [ 8, 9, 4 ],
//   [ 7, 6, 5 ]
// ]

#ifndef LEETCODECPP_SPIRALMATRIXII_H
#define LEETCODECPP_SPIRALMATRIXII_H

#include <vector>

namespace lcpp {

class Solution59_1 {
public:
  std::vector<std::vector<int>> generateMatrix(int n);
};

}

#endif //LEETCODECPP_SPIRALMATRIXII_H
