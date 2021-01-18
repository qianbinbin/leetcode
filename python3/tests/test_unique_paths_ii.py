from unittest import TestCase

from leetcodepy.unique_paths_ii import *

solution1 = Solution1()

obstacle_grid = [
    [0, 0, 0],
    [0, 1, 0],
    [0, 0, 0]
]

expected = 2


class TestUniquePathsII(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.uniquePathsWithObstacles(obstacle_grid))
