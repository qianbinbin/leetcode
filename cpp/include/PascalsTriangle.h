// Given an integer numRows, return the first numRows of Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
//
// https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
//
//
// Example 1:
//
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//
// Example 2:
//
// Input: numRows = 1
// Output: [[1]]
//
//
// Constraints:
//
// 1 <= numRows <= 30

#ifndef LEETCODECPP_PASCALSTRIANGLE_H
#define LEETCODECPP_PASCALSTRIANGLE_H

#include <vector>

namespace lcpp {

class Solution118_1 {
public:
  std::vector<std::vector<int>> generate(int numRows);
};

} // namespace lcpp

#endif // LEETCODECPP_PASCALSTRIANGLE_H
