from unittest import TestCase

from leetcodepy.balanced_binary_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

root1 = trees.from_values(3, 9, 20, None, None, 15, 7)

root2 = trees.from_values(1, 2, 2, 3, 3, None, None, 4, 4)


class TestBalancedBinaryTree(TestCase):
    def test1(self):
        self.assertTrue(solution1.isBalanced(root1))
        self.assertFalse(solution1.isBalanced(root2))
