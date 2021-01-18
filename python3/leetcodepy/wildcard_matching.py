"""
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
"""


class Solution1:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        size_s, size_p = len(s), len(p)
        dp = [[False] * (size_p + 1) for _ in range(size_s + 1)]
        dp[0][0] = True
        for j in range(1, size_p + 1):
            if p[j - 1] == '*':
                dp[0][j] = True
            else:
                break
        for i in range(1, size_s + 1):
            for j in range(1, size_p + 1):
                if p[j - 1] == '?' or p[j - 1] == s[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
        return dp[size_s][size_p]


class Solution2:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        len_s, len_p = len(s), len(p)
        i, j = 0, 0
        star, last_str = -1, -1
        while i < len_s:
            ch = p[j] if j < len_p else None
            if ch == '?' or ch == s[i]:
                i += 1
                j += 1
            elif ch == '*':
                last_str = i
                star = j
                j += 1
            elif star != -1:
                last_str += 1
                i = last_str
                j = star + 1
            else:
                return False
        while j < len_p and p[j] == '*':
            j += 1
        return j == len_p
