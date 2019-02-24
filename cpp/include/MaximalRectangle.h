// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

#ifndef LEETCODECPP_MAXIMALRECTANGLE_H
#define LEETCODECPP_MAXIMALRECTANGLE_H

#include <vector>

namespace lcpp {

class Solution85_1 {
public:
  int maximalRectangle(std::vector<std::vector<char>> &matrix);
};

class Solution85_2 {
public:
  int maximalRectangle(std::vector<std::vector<char>> &matrix);
};

}

#endif //LEETCODECPP_MAXIMALRECTANGLE_H
