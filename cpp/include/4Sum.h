// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#ifndef LEETCODECPP_4SUM_H
#define LEETCODECPP_4SUM_H

#include <vector>

namespace lcpp {

class Solution18_1 {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target);
};

class Solution18_2 {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target);
};

}

#endif //LEETCODECPP_4SUM_H
