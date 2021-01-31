"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
"""
from typing import List


class Solution1:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        for j in range(len(strs[0])):
            ch = strs[0][j]
            for i in range(1, len(strs)):
                if j >= len(strs[i]) or strs[i][j] != ch:
                    return strs[0][:j]
        return strs[0]
