from unittest import TestCase

from leetcodepy.divide_two_integers import *

SOLUTION1 = Solution1()

DIVIDEND1 = 10
DIVISOR1 = 3
EXPECTED1 = 3

DIVIDEND2 = 7
DIVISOR2 = -3
EXPECTED2 = -2

DIVIDEND3 = 0
DIVISOR3 = 1
EXPECTED3 = 0

DIVIDEND4 = 1
DIVISOR4 = 1
EXPECTED4 = 1


class TestDivideTwoIntegers(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.divide(DIVIDEND1, DIVISOR1))
        self.assertEqual(EXPECTED2, SOLUTION1.divide(DIVIDEND2, DIVISOR2))
        self.assertEqual(EXPECTED3, SOLUTION1.divide(DIVIDEND3, DIVISOR3))
        self.assertEqual(EXPECTED4, SOLUTION1.divide(DIVIDEND4, DIVISOR4))
