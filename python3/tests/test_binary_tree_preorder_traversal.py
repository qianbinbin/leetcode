from unittest import TestCase

from leetcodepy.binary_tree_preorder_traversal import *
from leetcodepy.utils import trees

solution1 = Solution1()

solution2 = Solution2()

root = trees.from_values(1, None, 2, 3)

expected = [1, 2, 3]


class TestBinaryTreePreorderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.preorderTraversal(root))

    def test2(self):
        self.assertListEqual(expected, solution2.preorderTraversal(root))
