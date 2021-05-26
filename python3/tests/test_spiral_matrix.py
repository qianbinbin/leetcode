from unittest import TestCase

from leetcodepy.spiral_matrix import *

SOLUTION1 = Solution1()

MATRIX1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
EXPECTED1 = [1, 2, 3, 6, 9, 8, 7, 4, 5]

MATRIX2 = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]
EXPECTED2 = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]


class TestSpiralMatrix(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.spiralOrder(MATRIX1))
        self.assertListEqual(EXPECTED2, SOLUTION1.spiralOrder(MATRIX2))
