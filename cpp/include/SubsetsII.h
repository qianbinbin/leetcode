// Given an integer array nums that may contain duplicates, return all possible
// subsets (the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
//
//
// Example 1:
//
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//
// Example 2:
//
// Input: nums = [0]
// Output: [[],[0]]
//
//
// Constraints:
//
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#ifndef LEETCODECPP_SUBSETSII_H
#define LEETCODECPP_SUBSETSII_H

#include <vector>

namespace lcpp {

class Solution90_1 {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums);
};

} // namespace lcpp

#endif // LEETCODECPP_SUBSETSII_H
