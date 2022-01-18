from unittest import TestCase

from leetcodepy.minimum_path_sum import *

SOLUTION1 = Solution1()

GRID1 = [
    [1, 3, 1],
    [1, 5, 1],
    [4, 2, 1]
]
EXPECTED1 = 7

GRID2 = [
    [1, 2, 3],
    [4, 5, 6]
]
EXPECTED2 = 12


class TestMinimumPathSum(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minPathSum(GRID1))
        self.assertEqual(EXPECTED2, SOLUTION1.minPathSum(GRID2))
