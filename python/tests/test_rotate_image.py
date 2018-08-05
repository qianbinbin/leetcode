from unittest import TestCase

from rotate_image import *

solution1 = Solution1()

expected1 = [
    [7, 4, 1],
    [8, 5, 2],
    [9, 6, 3]
]

expected2 = [
    [15, 13, 2, 5],
    [14, 3, 4, 1],
    [12, 6, 8, 9],
    [16, 7, 10, 11]
]


class TestRotateImage(TestCase):
    def test1(self):
        matrix1 = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        solution1.rotate(matrix1)
        self.assertEqual(matrix1, expected1)

        matrix2 = [
            [5, 1, 9, 11],
            [2, 4, 8, 10],
            [13, 3, 6, 7],
            [15, 14, 12, 16]
        ]
        solution1.rotate(matrix2)
        self.assertEqual(matrix2, expected2)
