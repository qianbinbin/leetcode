// Given a string s, partition s such that every substring of the partition is a
// palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

#ifndef LEETCODECPP_PALINDROMEPARTITIONING_H
#define LEETCODECPP_PALINDROMEPARTITIONING_H

#include <string>
#include <vector>

namespace lcpp {

class Solution131_1 {
public:
  std::vector<std::vector<std::string>> partition(std::string s);
};

} // namespace lcpp

#endif // LEETCODECPP_PALINDROMEPARTITIONING_H
