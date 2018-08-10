from unittest import TestCase

from leetcodepy.longest_valid_parentheses import *

solution1 = Solution1()

s1 = "(()"

expected1 = 2

s2 = ")()())"

expected2 = 4


class TestLongestValidParentheses(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.longestValidParentheses(s1))
        self.assertEqual(expected2, solution1.longestValidParentheses(s2))
