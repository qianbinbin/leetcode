from unittest import TestCase

from leetcodepy.path_sum_ii import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1)
TARGETSUM1 = 22
EXPECTED1 = [
    [5, 4, 11, 2],
    [5, 8, 4, 5]
]

ROOT2 = trees.from_values(1, 2, 3)
TARGETSUM2 = 5
EXPECTED2 = []

ROOT3 = trees.from_values(1, 2)
TARGETSUM3 = 0
EXPECTED3 = []


class TestPathSumII(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.pathSum(ROOT1, TARGETSUM1))
        self.assertListEqual(EXPECTED2, SOLUTION1.pathSum(ROOT2, TARGETSUM2))
        self.assertListEqual(EXPECTED3, SOLUTION1.pathSum(ROOT3, TARGETSUM3))
