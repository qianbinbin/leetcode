from unittest import TestCase

from leetcodepy.spiral_matrix_ii import *

solution1 = Solution1()

n = 3

expected = [
    [1, 2, 3],
    [8, 9, 4],
    [7, 6, 5]
]


class TestSpiralMatrixII(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.generateMatrix(n))
