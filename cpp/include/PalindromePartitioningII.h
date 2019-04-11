// Given a string s, partition s such that every substring of the partition is a
// palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
// cut.

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
