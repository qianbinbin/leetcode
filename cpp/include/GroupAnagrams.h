// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
// An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly
// once.
//
//
//
// Example 1:
//
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Example 2:
//
// Input: strs = [""]
// Output: [[""]]
//
// Example 3:
//
// Input: strs = ["a"]
// Output: [["a"]]
//
//
// Constraints:
//
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.

#ifndef LEETCODECPP_GROUPANAGRAMS_H
#define LEETCODECPP_GROUPANAGRAMS_H

#include <string>
#include <vector>

namespace lcpp {

class Solution49_1 {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs);
};

} // namespace lcpp

#endif // LEETCODECPP_GROUPANAGRAMS_H
