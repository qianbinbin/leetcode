from unittest import TestCase

from leetcodepy.path_sum import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1)
TARGETSUM1 = 22
EXPECTED1 = True

ROOT2 = trees.from_values(1, 2, 3)
TARGETSUM2 = 5
EXPECTED2 = False

ROOT3 = trees.from_values()
TARGETSUM3 = 0
EXPECTED3 = False


class TestPathSum(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.hasPathSum(ROOT1, TARGETSUM1))
        self.assertEqual(EXPECTED2, SOLUTION1.hasPathSum(ROOT2, TARGETSUM2))
        self.assertEqual(EXPECTED3, SOLUTION1.hasPathSum(ROOT3, TARGETSUM3))
