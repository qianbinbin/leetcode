"""
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
"""


class Solution1:
    def longestValidParentheses(self, s: str) -> int:
        result = 0
        top = -1
        start = -1
        for i in range(len(s)):
            if s[i] == '(':
                top += 1
            elif s[i] == ')':
                if top >= 0:
                    top -= 1
                    if top == -1:
                        result = max(result, i - start)
                else:
                    start = i
        top = -1
        start = len(s)
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ')':
                top += 1
            elif s[i] == '(':
                if top >= 0:
                    top -= 1
                    if top == -1:
                        result = max(result, start - i)
                else:
                    start = i
        return result


class Solution2:
    def longestValidParentheses(self, s: str) -> int:
        result = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    result = max(result, i - stack[-1])
        return result


class Solution3:
    def longestValidParentheses(self, s: str) -> int:
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
