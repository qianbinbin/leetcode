from unittest import TestCase

from leetcodepy.evaluate_reverse_polish_notation import *

solution1 = Solution1()

tokens1 = ["2", "1", "+", "3", "*"]

expected1 = 9

tokens2 = ["4", "13", "5", "/", "+"]

expected2 = 6

tokens3 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]

expected3 = 22


class TestEvaluateReversePolishNotation(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.evalRPN(tokens1))
        self.assertEqual(expected2, solution1.evalRPN(tokens2))
        self.assertEqual(expected3, solution1.evalRPN(tokens3))
