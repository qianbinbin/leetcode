from unittest import TestCase

from leetcodepy.construct_binary_tree_from_inorder_and_postorder_traversal import *
from leetcodepy.utils import trees

solution1 = Solution1()

in_order = [9, 3, 15, 20, 7]

post_order = [9, 15, 7, 20, 3]

expected = trees.from_values(3, 9, 20, None, None, 15, 7)


class TestConstructBinaryTreeFromInorderAndPostorderTraversal(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(expected, solution1.buildTree(in_order, post_order)))
