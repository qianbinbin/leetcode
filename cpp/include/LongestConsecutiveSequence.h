// Given an unsorted array of integers, find the length of the longest
// consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

#ifndef LEETCODECPP_LONGESTCONSECUTIVESEQUENCE_H
#define LEETCODECPP_LONGESTCONSECUTIVESEQUENCE_H

#include <vector>

namespace lcpp {

class Solution128_1 {
public:
  int longestConsecutive(std::vector<int> &nums);
};

class Solution128_2 {
public:
  int longestConsecutive(std::vector<int> &nums);
};

}

#endif //LEETCODECPP_LONGESTCONSECUTIVESEQUENCE_H
