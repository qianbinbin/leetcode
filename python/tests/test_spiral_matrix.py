from unittest import TestCase

from spiral_matrix import *

solution1 = Solution1()

matrix1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

expected1 = [1, 2, 3, 6, 9, 8, 7, 4, 5]

matrix2 = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]

expected2 = [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]


class TestSpiralMatrix(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.spiralOrder(matrix1))
        self.assertListEqual(expected2, solution1.spiralOrder(matrix2))
