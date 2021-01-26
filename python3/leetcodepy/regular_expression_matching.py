"""
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false


Constraints:

0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
"""


class Solution1:
    def __match(self, s: str, p: str) -> bool:
        if p[0] == '\0':
            return s[0] == '\0'
        if s[0] == '\0':
            return p[1] == '*' and self.isMatch(s, p[2:])
        if p[1] == '*':
            if p[0] == '.' or p[0] == s[0]:
                return self.__match(s, p[2:]) or self.__match(s[1:], p)
            return self.__match(s, p[2:])
        return (p[0] == '.' or p[0] == s[0]) and self.__match(s[1:], p[1:])

    def isMatch(self, s: str, p: str) -> bool:
        return self.__match(s + '\0', p + '\0')


class Solution2:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        if n == 0:
            return m == 0
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for j in range(2, n + 1, 2):
            if p[j - 1] == '*':
                dp[0][j] = True
            else:
                break
        if m > 0:
            dp[1][1] = p[0] == '.' or p[0] == s[0]
        for i in range(1, m + 1):
            for j in range(2, n + 1):
                if p[j - 1] != '*':
                    dp[i][j] = (p[j - 1] == '.' or p[j - 1] == s[i - 1]) and dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 2] or ((p[j - 2] == '.' or p[j - 2] == s[i - 1]) and dp[i - 1][j])
        return dp[m][n]
