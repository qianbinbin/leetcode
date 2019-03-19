// Given a string, find the length of the longest substring without repeating
// characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
// Example 2:
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a
// substring.

#ifndef LEETCODECPP_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
#define LEETCODECPP_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H

#include <string>

namespace lcpp {

class Solution3_1 {
public:
  int lengthOfLongestSubstring(std::string s);
};

}

#endif //LEETCODECPP_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H
