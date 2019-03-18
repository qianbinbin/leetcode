// Given an array of integers nums sorted in ascending order, find the starting
// and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
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

#ifndef LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
#define LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H

#include <vector>

namespace lcpp {

class Solution34_1 {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target);
};

}

#endif //LEETCODECPP_FINDFIRSTANDLASTPOSITIONOFELEMENTINSORTEDARRAY_H
