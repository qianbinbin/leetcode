from unittest import TestCase

from leetcodepy.n_queens import *

solution1 = Solution1()

n = 4

expected = [
    [".Q..",
     "...Q",
     "Q...",
     "..Q."],

    ["..Q.",
     "Q...",
     "...Q",
     ".Q.."]
]


class TestNQueens(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.solveNQueens(n))
