// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, determine if s can be segmented into a space-separated
// sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the
// segmentation.
// You may assume the dictionary does not contain duplicate words.
//
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple
// pen apple".
// Note that you are allowed to reuse a dictionary word.
//
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

#ifndef LEETCODECPP_WORDBREAK_H
#define LEETCODECPP_WORDBREAK_H

#include <string>
#include <vector>

namespace lcpp {

class Solution132_1 {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict);
};

} // namespace lcpp

#endif // LEETCODECPP_WORDBREAK_H
