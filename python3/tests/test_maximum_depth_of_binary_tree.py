from unittest import TestCase

from leetcodepy.maximum_depth_of_binary_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(3, 9, 20, None, None, 15, 7)
EXPECTED1 = 3

ROOT2 = trees.from_values(1, None, 2)
EXPECTED2 = 2


class TestMaximumDepthOfBinaryTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxDepth(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxDepth(ROOT2))
