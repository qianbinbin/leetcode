// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#ifndef LEETCODECPP_NEXTPERMUTATION_H
#define LEETCODECPP_NEXTPERMUTATION_H

#include <vector>

namespace lcpp {

class Solution31_1 {
public:
  void nextPermutation(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_NEXTPERMUTATION_H
