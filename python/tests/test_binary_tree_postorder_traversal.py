from unittest import TestCase

from leetcodepy.binary_tree_postorder_traversal import *
from leetcodepy.utils import trees

solution1 = Solution1()

solution2 = Solution2()

root = trees.from_values(1, None, 2, 3)

expected = [3, 2, 1]


class TestBinaryTreePostorderTraversal(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.postorderTraversal(root))

    def test2(self):
        self.assertListEqual(expected, solution2.postorderTraversal(root))
