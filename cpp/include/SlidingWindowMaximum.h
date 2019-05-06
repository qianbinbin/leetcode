// Given an array nums, there is a sliding window of size k which is moving from
// the very left of the array to the very right. You can only see the k numbers
// in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
//
// Example:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
// array.
//
// Follow up:
// Could you solve it in linear time?

#ifndef LEETCODECPP_SLIDINGWINDOWMAXIMUM_H
#define LEETCODECPP_SLIDINGWINDOWMAXIMUM_H

#include <vector>

namespace lcpp {

class Solution239_1 {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);
};

class Solution239_2 {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);
};

} // namespace lcpp

#endif // LEETCODECPP_SLIDINGWINDOWMAXIMUM_H
