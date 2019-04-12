// Given an integer array nums, find the contiguous subarray within an array
// (containing at least one number) which has the largest product.
//
// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#ifndef LEETCODECPP_MAXIMUMPRODUCTSUBARRAY_H
#define LEETCODECPP_MAXIMUMPRODUCTSUBARRAY_H

#include <vector>

namespace lcpp {

class Solution152_1 {
public:
  int maxProduct(std::vector<int> &nums);
};

} // namespace lcpp

#endif // LEETCODECPP_MAXIMUMPRODUCTSUBARRAY_H
