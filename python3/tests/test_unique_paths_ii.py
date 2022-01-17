from unittest import TestCase

from leetcodepy.unique_paths_ii import *

SOLUTION1 = Solution1()

OBSTACLE_GRID1 = [
    [0, 0, 0],
    [0, 1, 0],
    [0, 0, 0]
]
EXPECTED1 = 2

OBSTACLE_GRID2 = [
    [0, 1],
    [0, 0]
]
EXPECTED2 = 1


class TestUniquePathsII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.uniquePathsWithObstacles(OBSTACLE_GRID1))
        self.assertEqual(EXPECTED2, SOLUTION1.uniquePathsWithObstacles(OBSTACLE_GRID2))
