from unittest import TestCase

from set_matrix_zeroes import *

solution1 = Solution1()

expected1 = [
    [1, 0, 1],
    [0, 0, 0],
    [1, 0, 1]
]

expected2 = [
    [0, 0, 0, 0],
    [0, 4, 5, 0],
    [0, 3, 1, 0]
]


class TestSetMatrixZeroes(TestCase):
    def test1(self):
        matrix1 = [
            [1, 1, 1],
            [1, 0, 1],
            [1, 1, 1]
        ]
        solution1.setZeroes(matrix1)
        self.assertListEqual(expected1, matrix1)
        matrix2 = [
            [0, 1, 2, 0],
            [3, 4, 5, 2],
            [1, 3, 1, 5]
        ]
        solution1.setZeroes(matrix2)
        self.assertListEqual(expected2, matrix2)
