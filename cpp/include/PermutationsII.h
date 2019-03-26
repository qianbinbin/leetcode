// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#ifndef LEETCODECPP_PERMUTATIONSII_H
#define LEETCODECPP_PERMUTATIONSII_H

#include <vector>

namespace lcpp {

class Solution47_1 {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_PERMUTATIONSII_H
