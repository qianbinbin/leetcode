"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
"""
from typing import List


class Solution1:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.generate_parenthesis(n, result, '', 0, 0)
        return result

    def generate_parenthesis(self, n: int, result: List[str], path: str, stack_size: int, left_count: int):
        if len(path) == 2 * n:
            result.append(path)
            return
        if left_count < n:
            self.generate_parenthesis(n, result, path + '(', stack_size + 1, left_count + 1)
        if stack_size > 0:
            self.generate_parenthesis(n, result, path + ')', stack_size - 1, left_count)
