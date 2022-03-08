// Given a string s, partition s such that every substring of the partition is a
// palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
//
//
// Example 1:
//
// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
// cut.
//
// Example 2:
//
// Input: s = "a"
// Output: 0
//
// Example 3:
//
// Input: s = "ab"
// Output: 1
//
//
// Constraints:
//
// 1 <= s.length <= 2000
// s consists of lower-case English letters only.

#ifndef LEETCODECPP_PALINDROMEPARTITIONINGII_H
#define LEETCODECPP_PALINDROMEPARTITIONINGII_H

#include <string>

namespace lcpp {

class Solution132_1 {
public:
  int minCut(std::string s);
};

class Solution132_2 {
public:
  int minCut(std::string s);
};

} // namespace lcpp

#endif // LEETCODECPP_PALINDROMEPARTITIONINGII_H
