// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.
//
// Example:
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
//
// 1. You must do this in-place without making a copy of the array.
// 2. Minimize the total number of operations.

#ifndef LEETCODECPP_MOVEZEROES_H
#define LEETCODECPP_MOVEZEROES_H

#include <vector>

namespace lcpp {

class Solution283_1 {
public:
  void moveZeroes(std::vector<int> &nums);
};

} // namespace lcpp

#endif // LEETCODECPP_MOVEZEROES_H
