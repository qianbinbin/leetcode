from unittest import TestCase

from leetcodepy.rotate_image import *

SOLUTION1 = Solution1()


def MATRIX1():
    return [[1, 2, 3], [4, 5, 6], [7, 8, 9]]


EXPECTED1 = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


def MATRIX2():
    return [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]


EXPECTED2 = [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]


def MATRIX3():
    return [[1]]


EXPECTED3 = [[1]]


def MATRIX4():
    return [[1, 2], [3, 4]]


EXPECTED4 = [[3, 1], [4, 2]]


class TestRotateImage(TestCase):
    def test1(self):
        matrix1 = MATRIX1()
        SOLUTION1.rotate(matrix1)
        self.assertEqual(matrix1, EXPECTED1)

        matrix2 = MATRIX2()
        SOLUTION1.rotate(matrix2)
        self.assertEqual(matrix2, EXPECTED2)

        matrix3 = MATRIX3()
        SOLUTION1.rotate(matrix3)
        self.assertEqual(matrix3, EXPECTED3)

        matrix4 = MATRIX4()
        SOLUTION1.rotate(matrix4)
        self.assertEqual(matrix4, EXPECTED4)
