from unittest import TestCase

from leetcodepy.n_queens_ii import *

SOLUTION1 = Solution1()

N1 = 4
EXPECTED1 = 2

N2 = 1
EXPECTED2 = 1


class TestNQueensII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.totalNQueens(N1))
        self.assertEqual(EXPECTED2, SOLUTION1.totalNQueens(N2))
