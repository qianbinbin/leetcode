from unittest import TestCase

from leetcodepy.path_sum_ii import *
from leetcodepy.utils import trees

solution1 = Solution1()

root = trees.from_values(5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1)

_sum = 22

expected = [
    [5, 4, 11, 2],
    [5, 8, 4, 5]
]


class TestPathSumII(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.pathSum(root, _sum))
