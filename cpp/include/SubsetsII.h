// Given a collection of integers that might contain duplicates, nums, return
// all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#ifndef LEETCODECPP_SUBSETSII_H
#define LEETCODECPP_SUBSETSII_H

#include <vector>

namespace lcpp {

class Solution90_1 {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_SUBSETSII_H
