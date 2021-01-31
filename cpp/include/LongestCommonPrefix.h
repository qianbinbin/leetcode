// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".
//
//
//
// Example 1:
//
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
//
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Constraints:
//
// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.

#ifndef LEETCODECPP_LONGESTCOMMONPREFIX_H
#define LEETCODECPP_LONGESTCOMMONPREFIX_H

#include <string>
#include <vector>

namespace lcpp {

class Solution14_1 {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs);
};

} // namespace lcpp

#endif // LEETCODECPP_LONGESTCOMMONPREFIX_H
