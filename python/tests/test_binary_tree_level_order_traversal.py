from unittest import TestCase

from leetcodepy.binary_tree_level_order_traversal import *
from leetcodepy.utils import trees

solution1 = Solution1()

root = trees.from_values(3, 9, 20, None, None, 15, 7)

expected = [
    [3],
    [9, 20],
    [15, 7]
]


class TestBinaryTreeLevelOrderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.levelOrder(root))
