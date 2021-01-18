"""
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
"""


class Solution1:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = len(s)
        if size < 2:
            return 0
        dp = [0] * size
        if s[0] == '(' and s[1] == ')':
            dp[1] = 2
        result = dp[1]
        for i in range(2, size):
            if s[i] == ')':
                if s[i - 1] == ')' and dp[i - 1] > 0:
                    j = i - dp[i - 1] - 1
                    if j >= 0 and s[j] == '(':
                        dp[i] = dp[i - 1] + 2
                        if j > 0:
                            dp[i] += dp[j - 1]
                elif s[i - 1] == '(':
                    dp[i] = dp[i - 2] + 2
                result = max(result, dp[i])
        return result


class Solution2:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    result = max(result, i - stack[-1])
        return result
