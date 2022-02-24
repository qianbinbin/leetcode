from unittest import TestCase

from leetcodepy.pascals_triangle_ii import *

SOLUTION1 = Solution1()

ROWINDEX1 = 3
EXPECTED1 = [1, 3, 3, 1]

ROWINDEX2 = 0
EXPECTED2 = [1]

ROWINDEX3 = 1
EXPECTED3 = [1, 1]


class TestPascalsTriangleII(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.getRow(ROWINDEX1))
        self.assertListEqual(EXPECTED2, SOLUTION1.getRow(ROWINDEX2))
        self.assertListEqual(EXPECTED3, SOLUTION1.getRow(ROWINDEX3))
