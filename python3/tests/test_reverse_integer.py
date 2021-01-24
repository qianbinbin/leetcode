from unittest import TestCase

from leetcodepy.reverse_integer import *

SOLUTION1 = Solution1()

X1 = 123
EXPECTED1 = 321

X2 = -123
EXPECTED2 = -321

X3 = 120
EXPECTED3 = 21

X4 = 0
EXPECTED4 = 0


class TestReverseInteger(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.reverse(X1))
        self.assertEqual(EXPECTED2, SOLUTION1.reverse(X2))
        self.assertEqual(EXPECTED3, SOLUTION1.reverse(X3))
        self.assertEqual(EXPECTED4, SOLUTION1.reverse(X4))
