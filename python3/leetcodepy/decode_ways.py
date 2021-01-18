"""
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
"""


class Solution1:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            raise ValueError
        size = len(s)
        dp = [0] * size
        if s[0] != '0':
            dp[0] = 1
        if size == 1:
            return dp[0]
        if s[1] == '0':
            if 1 <= int(s[0]) <= 2:
                dp[1] = 1
        else:
            dp[1] = dp[0]
            if s[0] != '0' and int(s[:2]) <= 26:
                dp[1] += 1
        if dp[0] == 0 or dp[1] == 0:
            return 0
        for i in range(2, size):
            if s[i] == '0':
                if 1 <= int(s[i - 1]) <= 2:
                    dp[i] = dp[i - 2]
            else:
                dp[i] = dp[i - 1]
                if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                    dp[i] += dp[i - 2]
            if dp[i] == 0:
                return 0
        return dp[size - 1]
