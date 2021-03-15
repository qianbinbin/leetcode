from unittest import TestCase

from leetcodepy.valid_parentheses import *

SOLUTION1 = Solution1()

S1 = "()"
EXPECTED1 = True

S2 = "()[]{}"
EXPECTED2 = True

S3 = "(]"
EXPECTED3 = False

S4 = "([)]"
EXPECTED4 = False

S5 = "{[]}"
EXPECTED5 = True


class TestValidParentheses(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isValid(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.isValid(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.isValid(S3))
        self.assertEqual(EXPECTED4, SOLUTION1.isValid(S4))
        self.assertEqual(EXPECTED5, SOLUTION1.isValid(S5))
