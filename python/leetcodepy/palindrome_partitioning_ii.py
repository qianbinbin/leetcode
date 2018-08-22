"""
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
"""


class Solution1:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
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
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = len(s)
        cut = [i - 1 for i in range(size + 1)]
        for i in range(size):
            len_ = 0
            while i - len_ >= 0 and i + len_ < size and s[i - len_] == s[i + len_]:
                cut[i + len_ + 1] = min(cut[i + len_ + 1], cut[i - len_] + 1)
                len_ += 1
            len_ = 0
            while i - len_ >= 0 and i + len_ + 1 < size and s[i - len_] == s[i + len_ + 1]:
                cut[i + len_ + 2] = min(cut[i + len_ + 2], cut[i - len_] + 1)
                len_ += 1
        return cut[size]
