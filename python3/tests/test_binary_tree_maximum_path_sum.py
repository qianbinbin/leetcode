from unittest import TestCase

from leetcodepy.binary_tree_maximum_path_sum import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(1, 2, 3)
EXPECTED1 = 6

ROOT2 = trees.from_values(-10, 9, 20, None, None, 15, 7)
EXPECTED2 = 42


class TestBinaryTreeMaximumPathSum(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxPathSum(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxPathSum(ROOT2))
