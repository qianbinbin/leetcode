from unittest import TestCase

from leetcodepy.n_queens import *

SOLUTION1 = Solution1()

N1 = 4
EXPECTED1 = [
    [".Q..", "...Q", "Q...", "..Q."],
    ["..Q.", "Q...", "...Q", ".Q.."]
]

N2 = 1
EXPECTED2 = [
    ["Q"]
]


class TestNQueens(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.solveNQueens(N1))
        self.assertListEqual(EXPECTED2, SOLUTION1.solveNQueens(N2))
