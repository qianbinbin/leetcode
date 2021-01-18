from unittest import TestCase

from leetcodepy.minimum_path_sum import *

solution1 = Solution1()

grid = [
    [1, 3, 1],
    [1, 5, 1],
    [4, 2, 1]
]

expected = 7


class TestMinimumPathSum(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.minPathSum(grid))
