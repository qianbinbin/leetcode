// Given a non-negative integer numRows, generate the first numRows of Pascal's
// triangle.
//
// https://upload.wikimedia.org/wikipedia/commons/0/0d/
// PascalTriangleAnimated2.gif
//
// In Pascal's triangle, each number is the sum of the two numbers directly
// above it.
//
// Example:
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#ifndef LEETCODECPP_PASCALSTRIANGLE_H
#define LEETCODECPP_PASCALSTRIANGLE_H

#include <vector>

namespace lcpp {

class Solution118_1 {
public:
  std::vector<std::vector<int>> generate(int numRows);
};

}

#endif //LEETCODECPP_PASCALSTRIANGLE_H
