from unittest import TestCase

from leetcodepy.generate_parentheses import *

SOLUTION1 = Solution1()

N1 = 3
EXPECTED1 = ["((()))", "(()())", "(())()", "()(())", "()()()"]

N2 = 1
EXPECTED2 = ["()"]


class TestGenerateParentheses(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.generateParenthesis(N1))
        self.assertEqual(EXPECTED2, SOLUTION1.generateParenthesis(N2))
