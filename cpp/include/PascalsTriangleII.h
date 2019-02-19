// Given a non-negative index k where k ≤ 33, return the kth index row of the
// Pascal's triangle.
//
// Note that the row index starts from 0.
//
// https://upload.wikimedia.org/wikipedia/commons/0/0d/
// PascalTriangleAnimated2.gif
//
// In Pascal's triangle, each number is the sum of the two numbers directly
// above it.
//
// Example:
//
// Input: 3
// Output: [1,3,3,1]
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?

#ifndef LEETCODECPP_PASCALSTRIANGLEII_H
#define LEETCODECPP_PASCALSTRIANGLEII_H

#include <vector>

namespace lcpp {

class Solution119_1 {
public:
  std::vector<int> getRow(int rowIndex);
};

}

#endif //LEETCODECPP_PASCALSTRIANGLEII_H
