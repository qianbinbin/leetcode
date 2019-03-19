// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
//     Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#ifndef LEETCODECPP_TWOSUM_H
#define LEETCODECPP_TWOSUM_H

#include <vector>

namespace lcpp {

class Solution1_1 {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target);
};

}

#endif //LEETCODECPP_TWOSUM_H
