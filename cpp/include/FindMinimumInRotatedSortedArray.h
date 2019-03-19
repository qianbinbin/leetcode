// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
// Input: [3,4,5,1,2]
// Output: 1
//
// Example 2:
//
// Input: [4,5,6,7,0,1,2]
// Output: 0

#ifndef LEETCODECPP_FINDMINIMUMINROTATEDSORTEDARRAY_H
#define LEETCODECPP_FINDMINIMUMINROTATEDSORTEDARRAY_H

#include <vector>

namespace lcpp {

class Solution153_1 {
public:
  int findMin(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_FINDMINIMUMINROTATEDSORTEDARRAY_H
