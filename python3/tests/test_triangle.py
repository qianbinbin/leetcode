from unittest import TestCase

from leetcodepy.triangle import *

SOLUTION1 = Solution1()

TRIANGLE1 = [
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]

EXPECTED1 = 11

TRIANGLE2 = [
    [-10]
]

EXPECTED2 = -10


class TestTriangle(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minimumTotal(TRIANGLE1))
        self.assertEqual(EXPECTED2, SOLUTION1.minimumTotal(TRIANGLE2))
