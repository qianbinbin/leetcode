"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
"""
from typing import List, Optional


class Solution1:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n < 0:
            raise ValueError
        result = []
        self.generate_parenthesis(n, result, '', 0, 0, 0)
        return result

    def generate_parenthesis(self, n: int, result: List[str], path: str, stack_size: int,
                             left_count: int, right_count: int):
        if len(path) == 2 * n:
            if stack_size == 0:
                result.append(path)
            return
        if stack_size < n and left_count < n:
            self.generate_parenthesis(n, result, path + '(', stack_size + 1, left_count + 1, right_count)
        if stack_size > 0 and right_count < n:
            self.generate_parenthesis(n, result, path + ')', stack_size - 1, left_count, right_count + 1)
