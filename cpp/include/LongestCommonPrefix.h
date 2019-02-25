// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
// Note:
//
// All given inputs are in lowercase letters a-z.

#ifndef LEETCODECPP_LONGESTCOMMONPREFIX_H
#define LEETCODECPP_LONGESTCOMMONPREFIX_H

#include <string>
#include <vector>

namespace lcpp {

class Solution14_1 {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs);
};

}

#endif //LEETCODECPP_LONGESTCOMMONPREFIX_H
