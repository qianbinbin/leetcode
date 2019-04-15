// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#ifndef LEETCODECPP_KTHLARGESTELEMENTINANARRAY_H
#define LEETCODECPP_KTHLARGESTELEMENTINANARRAY_H

#include <vector>

namespace lcpp {

class Solution215_1 {
public:
  int findKthLargest(std::vector<int> &nums, int k);
};

class Solution215_2 {
public:
  int findKthLargest(std::vector<int> &nums, int k);
};

class Solution215_3 {
public:
  int findKthLargest(std::vector<int> &nums, int k);
};

} // namespace lcpp

#endif // LEETCODECPP_KTHLARGESTELEMENTINANARRAY_H
