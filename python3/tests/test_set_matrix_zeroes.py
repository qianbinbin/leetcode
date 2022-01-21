from unittest import TestCase

from leetcodepy.set_matrix_zeroes import *

SOLUTION1 = Solution1()


def MATRIX1():
    return [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]


EXPECTED1 = [
    [1, 0, 1],
    [0, 0, 0],
    [1, 0, 1]
]


def MATRIX2():
    return [
        [0, 1, 2, 0],
        [3, 4, 5, 2],
        [1, 3, 1, 5]
    ]


EXPECTED2 = [
    [0, 0, 0, 0],
    [0, 4, 5, 0],
    [0, 3, 1, 0]
]


class TestSetMatrixZeroes(TestCase):
    def test1(self):
        matrix1 = MATRIX1()
        SOLUTION1.setZeroes(matrix1)
        self.assertListEqual(EXPECTED1, matrix1)

        matrix2 = MATRIX2()
        SOLUTION1.setZeroes(matrix2)
        self.assertListEqual(EXPECTED2, matrix2)
