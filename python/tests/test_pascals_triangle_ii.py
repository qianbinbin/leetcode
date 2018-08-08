from unittest import TestCase

from leetcodepy.pascals_triangle_ii import *

solution1 = Solution1()

rowIndex = 3

expected = [1, 3, 3, 1]


class TestPascalsTriangleII(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.getRow(rowIndex))
