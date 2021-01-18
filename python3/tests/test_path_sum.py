from unittest import TestCase

from leetcodepy.path_sum import *
from leetcodepy.utils import trees

solution1 = Solution1()

root = trees.from_values(5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1)

_sum = 22


class TestPathSum(TestCase):
    def test1(self):
        self.assertTrue(solution1.hasPathSum(root, _sum))
