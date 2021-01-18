from unittest import TestCase

from leetcodepy.powx_n import *

solution1 = Solution1()

delta = 0.00001

x1 = 2.00000

n1 = 10

expected1 = 1024.00000

x2 = 2.10000

n2 = 3

expected2 = 9.26100

x3 = 2.00000

n3 = -2

expected3 = 0.25000


class TestPowXN(TestCase):
    def test1(self):
        self.assertAlmostEqual(expected1, solution1.myPow(x1, n1), delta=delta)
        self.assertAlmostEqual(expected2, solution1.myPow(x2, n2), delta=delta)
        self.assertAlmostEqual(expected3, solution1.myPow(x3, n3), delta=delta)
