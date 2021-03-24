// Given an array of integers nums sorted in ascending order, find the starting
// and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// Follow up: Could you write an algorithm with O(log n) runtime complexity?
//
//
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
// Example 3:
//
// Input: nums = [], target = 0
// Output: [-1,-1]
//
//
// Constraints:
//
// 0 <= nums.length <= 10^5
//-10^9 <= nums[i] <= 10^9
// nums is a non-decreasing array.
//-10^9 <= target <= 10^9

#ifndef LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
#define LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H

#include <vector>

namespace lcpp {

class Solution34_1 {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target);
};

} // namespace lcpp

#endif // LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
