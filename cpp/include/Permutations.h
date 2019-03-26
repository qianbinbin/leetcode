// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#ifndef LEETCODECPP_PERMUTATIONS_H
#define LEETCODECPP_PERMUTATIONS_H

#include <vector>

namespace lcpp {

class Solution46_1 {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_PERMUTATIONS_H
