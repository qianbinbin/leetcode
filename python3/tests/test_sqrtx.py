from unittest import TestCase

from leetcodepy.sqrtx import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()
SOLUTION3 = Solution3()

X1 = 4
EXPECTED1 = 2

X2 = 8
EXPECTED2 = 2


class TestSqrt(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.mySqrt(X1))
        self.assertEqual(EXPECTED2, SOLUTION1.mySqrt(X2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.mySqrt(X1))
        self.assertEqual(EXPECTED2, SOLUTION2.mySqrt(X2))

    def test3(self):
        self.assertEqual(EXPECTED1, SOLUTION3.mySqrt(X1))
        self.assertEqual(EXPECTED2, SOLUTION3.mySqrt(X2))
