from unittest import TestCase

from leetcodepy.construct_binary_tree_from_preorder_and_inorder_traversal import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

PREORDER1 = [3, 9, 20, 15, 7]
INORDER1 = [9, 3, 15, 20, 7]
EXPECTED1 = trees.from_values(3, 9, 20, None, None, 15, 7)

PREORDER2 = [-1]
INORDER2 = [-1]
EXPECTED2 = trees.from_values(-1)


class TestConstructBinaryTreeFromPreorderAndInorderTraversal(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(EXPECTED1, SOLUTION1.buildTree(PREORDER1, INORDER1)))
        self.assertTrue(trees.equals(EXPECTED2, SOLUTION1.buildTree(PREORDER2, INORDER2)))
