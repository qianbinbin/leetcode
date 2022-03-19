from unittest import TestCase

from leetcodepy.evaluate_reverse_polish_notation import *

SOLUTION1 = Solution1()

TOKENS1 = ["2", "1", "+", "3", "*"]
EXPECTED1 = 9

TOKENS2 = ["4", "13", "5", "/", "+"]
EXPECTED2 = 6

TOKENS3 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
EXPECTED3 = 22


class TestEvaluateReversePolishNotation(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.evalRPN(TOKENS1))
        self.assertEqual(EXPECTED2, SOLUTION1.evalRPN(TOKENS2))
        self.assertEqual(EXPECTED3, SOLUTION1.evalRPN(TOKENS3))
