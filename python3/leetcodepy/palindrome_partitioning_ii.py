"""
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:

Input: s = "a"
Output: 0

Example 3:

Input: s = "ab"
Output: 1


Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
"""


class Solution1:
    def minCut(self, s: str) -> int:
        size = len(s)
        dp = [[False] * size for _ in range(size)]
        cut = [size - 1 - i for i in range(size + 1)]
        for i in range(size - 1, -1, -1):
            for j in range(i, size):
                if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    cut[i] = min(cut[i], cut[j + 1] + 1)
        return cut[0]


class Solution2:
    def minCut(self, s: str) -> int:
        size = len(s)
        cut = [i - 1 for i in range(size + 1)]
        for i in range(size):
            _len = 0
            while i - _len >= 0 and i + _len < size and s[i - _len] == s[i + _len]:
                cut[i + _len + 1] = min(cut[i + _len + 1], cut[i - _len] + 1)
                _len += 1
            _len = 0
            while i - _len >= 0 and i + _len + 1 < size and s[i - _len] == s[i + _len + 1]:
                cut[i + _len + 2] = min(cut[i + _len + 2], cut[i - _len] + 1)
                _len += 1
        return cut[size]
