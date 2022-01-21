from unittest import TestCase

from leetcodepy.search_a_2d_matrix import *

SOLUTION1 = Solution1()

MATRIX1 = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
TARGET1 = 3
EXPECTED1 = True

MATRIX2 = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
TARGET2 = 13
EXPECTED2 = False


class TestSearchA2DMatrix(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.searchMatrix(MATRIX1, TARGET1))
        self.assertEqual(EXPECTED2, SOLUTION1.searchMatrix(MATRIX2, TARGET2))
