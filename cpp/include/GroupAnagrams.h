// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
// All inputs will be in lowercase.
// The order of your output does not matter.

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

}

#endif //LEETCODECPP_GROUPANAGRAMS_H
