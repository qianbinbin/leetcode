"""
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
"""


class Solution1:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        dp = [[False] * size for _ in range(size)]
        start, end = 0, 0
        for i in range(size - 1, -1, -1):
            for j in range(i, size):
                if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    if j - i + 1 >= end - start:
                        start, end = i, j + 1
        return s[start:end]
