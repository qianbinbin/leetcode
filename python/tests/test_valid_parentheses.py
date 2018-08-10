from unittest import TestCase

from leetcodepy.valid_parentheses import *

solution1 = Solution1()

s1 = "()"

s2 = "()[]{}"

s3 = "(]"

s4 = "([)]"

s5 = "{[]}"


class TestValidParentheses(TestCase):
    def test1(self):
        self.assertTrue(solution1.isValid(s1))
        self.assertTrue(solution1.isValid(s2))
        self.assertFalse(solution1.isValid(s3))
        self.assertFalse(solution1.isValid(s4))
        self.assertTrue(solution1.isValid(s5))
