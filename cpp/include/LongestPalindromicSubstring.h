// Given a string s, return the longest palindromic substring in s.
//
//
//
// Example 1:
//
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
//
// Input: s = "cbbd"
// Output: "bb"
//
// Example 3:
//
// Input: s = "a"
// Output: "a"
//
// Example 4:
//
// Input: s = "ac"
// Output: "a"
//
//
// Constraints:
//
// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),

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
