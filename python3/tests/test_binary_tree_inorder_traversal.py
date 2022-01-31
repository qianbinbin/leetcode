from unittest import TestCase

from leetcodepy.binary_tree_inorder_traversal import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

ROOT1 = trees.from_values(1, None, 2, 3)
EXPECTED1 = [1, 3, 2]

ROOT2 = trees.from_values()
EXPECTED2 = []

ROOT3 = trees.from_values(1)
EXPECTED3 = [1]


class TestBinaryTreeInorderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.inorderTraversal(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION1.inorderTraversal(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION1.inorderTraversal(ROOT3))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.inorderTraversal(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION2.inorderTraversal(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION2.inorderTraversal(ROOT3))
