// Given a 2D binary matrix filled with 0's and 1's, find the largest square
// containing only 1's and return its area.
//
// Example:
//
// Input:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4

#ifndef LEETCODECPP_MAXIMALSQUARE_H
#define LEETCODECPP_MAXIMALSQUARE_H

#include <vector>

namespace lcpp {

class Solution221_1 {
public:
  int maximalSquare(std::vector<std::vector<char>> &matrix);
};

} // namespace lcpp

#endif // LEETCODECPP_MAXIMALSQUARE_H
