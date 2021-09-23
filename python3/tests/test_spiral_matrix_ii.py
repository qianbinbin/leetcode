from unittest import TestCase

from leetcodepy.spiral_matrix_ii import *

SOLUTION1 = Solution1()

N1 = 3

EXPECTED1 = [
    [1, 2, 3],
    [8, 9, 4],
    [7, 6, 5]
]


class TestSpiralMatrixII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.generateMatrix(N1))
