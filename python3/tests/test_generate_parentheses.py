from unittest import TestCase

from leetcodepy.generate_parentheses import *

solution1 = Solution1()

n = 3

expected = [
    "((()))",
    "(()())",
    "(())()",
    "()(())",
    "()()()"
]


class TestGenerateParentheses(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.generateParenthesis(n))
