from unittest import TestCase

from leetcodepy.combinations import *

SOLUTION1 = Solution1()

N1 = 4
K1 = 2

EXPECTED1 = [
    [1, 2],
    [1, 3],
    [1, 4],
    [2, 3],
    [2, 4],
    [3, 4]
]

N2 = 1
K2 = 1

EXPECTED2 = [
    [1]
]


class TestCombinations(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.combine(N1, K1))
        self.assertListEqual(EXPECTED2, SOLUTION1.combine(N2, K2))
