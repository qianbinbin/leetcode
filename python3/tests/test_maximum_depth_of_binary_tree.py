from unittest import TestCase

from leetcodepy.maximum_depth_of_binary_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

root = trees.from_values(3, 9, 20, None, None, 15, 7)

expected = 3


class TestMaximumDepthOfBinaryTree(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.maxDepth(root))
