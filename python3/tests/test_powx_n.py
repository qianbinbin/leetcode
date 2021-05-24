from unittest import TestCase

from leetcodepy.powx_n import *

SOLUTION1 = Solution1()

DELTA = 0.00001

X1 = 2.00000
N1 = 10
EXPECTED1 = 1024.00000

X2 = 2.10000
N2 = 3
EXPECTED2 = 9.26100

X3 = 2.00000
N3 = -2
EXPECTED3 = 0.25000


class TestPowXN(TestCase):
    def test1(self):
        self.assertAlmostEqual(EXPECTED1, SOLUTION1.myPow(X1, N1), delta=DELTA)
        self.assertAlmostEqual(EXPECTED2, SOLUTION1.myPow(X2, N2), delta=DELTA)
        self.assertAlmostEqual(EXPECTED3, SOLUTION1.myPow(X3, N3), delta=DELTA)
