"""
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
"""


class Solution1:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        len_s, len_p = len(s), len(p)
        dp = [[False] * (len_p + 1) for _ in range(len_s + 1)]
        dp[0][0] = True
        for j in range(2, len_p + 1):
            dp[0][j] = p[j - 1] == '*' and dp[0][j - 2]
        if len_s > 0 and len_p > 0:
            dp[1][1] = self.__match(s[0], p[0])
        for i in range(1, len_s + 1):
            for j in range(2, len_p + 1):
                if p[j - 1] == '*':
                    if self.__match(s[i - 1], p[j - 2]) and (dp[i][j - 2] or dp[i - 1][j]):
                        dp[i][j] = True
                    elif dp[i][j - 2]:
                        dp[i][j] = True
                elif self.__match(s[i - 1], p[j - 1]) and dp[i - 1][j - 1]:
                    dp[i][j] = True
        return dp[len_s][len_p]

    @staticmethod
    def __match(s_ch: str, p_ch: str):
        return p_ch == '.' or s_ch == p_ch
