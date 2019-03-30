// Given an input string (s) and a pattern (p), implement wildcard pattern
// matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
//
// Note:
//
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like
// ? or *.
//
// Example 1:
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
// Example 2:
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
// Example 3:
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not
// match 'b'.
//
// Example 4:
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*'
// matches the substring "dce".
//
// Example 5:
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

#ifndef LEETCODECPP_WILDCARDMATCHING_H
#define LEETCODECPP_WILDCARDMATCHING_H

#include <string>

namespace lcpp {

class Solution44_1 {
public:
  bool isMatch(std::string s, std::string p);
};

class Solution44_2 {
public:
  bool isMatch(std::string s, std::string p);
};

}

#endif //LEETCODECPP_WILDCARDMATCHING_H
