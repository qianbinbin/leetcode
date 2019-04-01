// Given a string s, find the longest palindromic substring in s. You may assume
// that the maximum length of s is 1000.
//
// Example 1:
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
//
// Input: "cbbd"
// Output: "bb"

#ifndef LEETCODECPP_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODECPP_LONGESTPALINDROMICSUBSTRING_H

#include <string>

namespace lcpp {

class Solution5_1 {
public:
  std::string longestPalindrome(std::string s);
};

} // namespace lcpp

#endif // LEETCODECPP_LONGESTPALINDROMICSUBSTRING_H
