// Given a set of distinct integers, nums, return all possible subsets (the
// power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#ifndef LEETCODECPP_SUBSETS_H
#define LEETCODECPP_SUBSETS_H

#include <vector>

namespace lcpp {

class Solution77_1 {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_SUBSETS_H
