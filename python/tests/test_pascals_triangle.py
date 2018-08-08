from unittest import TestCase

from pascals_triangle import *

solution1 = Solution1()

numsRows = 5

expected = [
    [1],
    [1, 1],
    [1, 2, 1],
    [1, 3, 3, 1],
    [1, 4, 6, 4, 1]
]


class TestPascalsTriangle(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.generate(numsRows))
