from unittest import TestCase

from leetcodepy.divide_two_integers import *

solution1 = Solution1()

dividend1 = 10

divisor1 = 3

expected1 = 3

dividend2 = 7

divisor2 = -3

expected2 = -2


class TestDivideTwoIntegers(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.divide(dividend1, divisor1))
        self.assertEqual(expected2, solution1.divide(dividend2, divisor2))
