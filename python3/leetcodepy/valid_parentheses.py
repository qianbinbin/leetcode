"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.
"""


class Solution1:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stack.append(ch)
            elif ch == ')':
                if not stack or '(' != stack.pop():
                    return False
            elif ch == '}':
                if not stack or '{' != stack.pop():
                    return False
            elif ch == ']':
                if not stack or '[' != stack.pop():
                    return False
            else:
                break
        return not stack
