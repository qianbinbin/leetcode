from unittest import TestCase

from leetcodepy.binary_tree_level_order_traversal_ii import *
from leetcodepy.utils import trees

solution1 = Solution1()

root = trees.from_values(3, 9, 20, None, None, 15, 7)

expected = [
    [15, 7],
    [9, 20],
    [3]
]


class TestBinaryTreeLevelOrderTraversalII(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.levelOrderBottom(root))
