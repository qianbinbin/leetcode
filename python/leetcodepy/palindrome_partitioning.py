"""
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
"""
from typing import List


class Solution1:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        size = len(s)
        dp = [[False] * size for _ in range(size)]
        for i in range(size - 1, -1, -1):
            for j in range(i, size):
                if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
        result = []
        self.__partition(s, 0, dp, result, [])
        return result

    def __partition(self, s: str, i: int, palindrome: List[List[bool]], result: List[List[str]], path: List[str]):
        if i == len(s):
            result.append(path[:])
            return
        for j in range(i, len(s)):
            if palindrome[i][j]:
                path.append(s[i:j + 1])
                self.__partition(s, j + 1, palindrome, result, path)
                path.pop()
