"""
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
"""


class Solution1:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        len1, len2 = len(s1), len(s2)
        if len1 + len2 != len(s3):
            return False
        dp = [False] * (len2 + 1)
        dp[0] = True
        for j in range(1, len2 + 1):
            if s2[j - 1] == s3[j - 1]:
                dp[j] = True
            else:
                break
        for i in range(1, len1 + 1):
            if dp[0] and s1[i - 1] != s3[i - 1]:
                dp[0] = False
            for j in range(1, len2 + 1):
                dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[len2]
