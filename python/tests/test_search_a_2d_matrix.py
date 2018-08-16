from unittest import TestCase

from leetcodepy.search_a_2d_matrix import *

solution1 = Solution1()

matrix1 = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]

target1 = 3

matrix2 = [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]

target2 = 13


class TestSearchA2DMatrix(TestCase):
    def test1(self):
        self.assertTrue(solution1.searchMatrix(matrix1, target1))
        self.assertFalse(solution1.searchMatrix(matrix2, target2))
