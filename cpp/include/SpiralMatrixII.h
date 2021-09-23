// Given a positive integer n, generate an n x n matrix filled with elements
// from 1 to n2 in spiral order.
//
//
//
// Example 1:
// https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg
//
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
//
// Example 2:
//
// Input: n = 1
// Output: [[1]]
//
//
// Constraints:
//
// 1 <= n <= 20

#ifndef LEETCODECPP_SPIRALMATRIXII_H
#define LEETCODECPP_SPIRALMATRIXII_H

#include <vector>

namespace lcpp {

class Solution59_1 {
public:
  std::vector<std::vector<int>> generateMatrix(int n);
};

} // namespace lcpp

#endif // LEETCODECPP_SPIRALMATRIXII_H
