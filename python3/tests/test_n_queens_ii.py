from unittest import TestCase

from leetcodepy.n_queens_ii import *

solution1 = Solution1()

n = 4

expected = 2


class TestNQueensII(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.totalNQueens(n))
