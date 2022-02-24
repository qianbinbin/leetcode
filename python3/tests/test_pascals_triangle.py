from unittest import TestCase

from leetcodepy.pascals_triangle import *

SOLUTION1 = Solution1()

NUMSROWS1 = 5
EXPECTED1 = [
    [1],
    [1, 1],
    [1, 2, 1],
    [1, 3, 3, 1],
    [1, 4, 6, 4, 1]
]

NUMSROWS2 = 1
EXPECTED2 = [
    [1]
]


class TestPascalsTriangle(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.generate(NUMSROWS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.generate(NUMSROWS2))
