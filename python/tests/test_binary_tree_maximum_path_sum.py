from unittest import TestCase

from leetcodepy.binary_tree_maximum_path_sum import *
from leetcodepy.utils import trees

solution1 = Solution1()

root1 = trees.from_values(1, 2, 3)

expected1 = 6

root2 = trees.from_values(-10, 9, 20, None, None, 15, 7)

expected2 = 42


class TestBinaryTreeMaximumPathSum(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxPathSum(root1))
        self.assertEqual(expected2, solution1.maxPathSum(root2))
