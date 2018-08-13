from unittest import TestCase

from leetcodepy.construct_binary_tree_from_preorder_and_inorder_traversal import *
from leetcodepy.utils import trees

solution1 = Solution1()

pre_order = [3, 9, 20, 15, 7]

in_order = [9, 3, 15, 20, 7]

expected = trees.from_values(3, 9, 20, None, None, 15, 7)


class TestConstructBinaryTreeFromPreorderAndInorderTraversal(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(expected, solution1.buildTree(pre_order, in_order)))
