from unittest import TestCase

from leetcodepy.construct_binary_tree_from_inorder_and_postorder_traversal import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

INORDER1 = [9, 3, 15, 20, 7]
POSTORDER1 = [9, 15, 7, 20, 3]
EXPECTED1 = trees.from_values(3, 9, 20, None, None, 15, 7)

INORDER2 = [-1]
POSTORDER2 = [-1]
EXPECTED2 = trees.from_values(-1)


class TestConstructBinaryTreeFromInorderAndPostorderTraversal(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(EXPECTED1, SOLUTION1.buildTree(INORDER1, POSTORDER1)))
        self.assertTrue(trees.equals(EXPECTED2, SOLUTION1.buildTree(INORDER2, POSTORDER2)))
