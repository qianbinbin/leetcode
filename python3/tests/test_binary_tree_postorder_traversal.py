from unittest import TestCase

from leetcodepy.binary_tree_postorder_traversal import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()
SOLUTION3 = Solution3()

ROOT1 = trees.from_values(1, None, 2, 3)
EXPECTED1 = [3, 2, 1]

ROOT2 = trees.from_values()
EXPECTED2 = []

ROOT3 = trees.from_values(1)
EXPECTED3 = [1]


class TestBinaryTreePostorderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.postorderTraversal(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION1.postorderTraversal(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION1.postorderTraversal(ROOT3))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.postorderTraversal(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION2.postorderTraversal(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION2.postorderTraversal(ROOT3))

    def test3(self):
        self.assertListEqual(EXPECTED1, SOLUTION3.postorderTraversal(ROOT1))
        self.assertListEqual(EXPECTED2, SOLUTION3.postorderTraversal(ROOT2))
        self.assertListEqual(EXPECTED3, SOLUTION3.postorderTraversal(ROOT3))
