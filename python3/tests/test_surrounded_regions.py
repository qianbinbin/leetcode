from unittest import TestCase

from leetcodepy.surrounded_regions import *

solution1 = Solution1()

expected = [
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'X', 'X']
]


class TestSurroundedRegions(TestCase):
    def test1(self):
        board = [
            ['X', 'X', 'X', 'X'],
            ['X', 'O', 'O', 'X'],
            ['X', 'X', 'O', 'X'],
            ['X', 'O', 'X', 'X']
        ]
        solution1.solve(board)
        self.assertListEqual(expected, board)
