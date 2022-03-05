from unittest import TestCase

from leetcodepy.surrounded_regions import *

SOLUTION1 = Solution1()


def BOARD1():
    return [['X', 'X', 'X', 'X'],
            ['X', 'O', 'O', 'X'],
            ['X', 'X', 'O', 'X'],
            ['X', 'O', 'X', 'X']]


EXPECTED1 = [
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'X', 'X']
]


def BOARD2():
    return [['X']]


EXPECTED2 = [['X']]


class TestSurroundedRegions(TestCase):
    def test1(self):
        board1 = BOARD1()
        SOLUTION1.solve(board1)
        self.assertListEqual(EXPECTED1, board1)

        board2 = BOARD2()
        SOLUTION1.solve(board2)
        self.assertListEqual(EXPECTED2, board2)
