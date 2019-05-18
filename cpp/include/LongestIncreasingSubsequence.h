// Given an unsorted array of integers, find the length of longest increasing
// subsequence.
//
// Example:
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.
//
// Note:
//
// There may be more than one LIS combination, it is only necessary for you to
// return the length. Your algorithm should run in O(n2) complexity.
//
// Follow up: Could you improve it to O(n log n) time complexity?

#ifndef LEETCODECPP_LONGESTINCREASINGSUBSEQUENCE_H
#define LEETCODECPP_LONGESTINCREASINGSUBSEQUENCE_H

#include <vector>

namespace lcpp {

class Solution300_1 {
public:
  int lengthOfLIS(std::vector<int> &nums);
};

} // namespace lcpp

#endif // LEETCODECPP_LONGESTINCREASINGSUBSEQUENCE_H
