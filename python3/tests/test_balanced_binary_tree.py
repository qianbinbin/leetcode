from unittest import TestCase

from leetcodepy.balanced_binary_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

ROOT1 = trees.from_values(3, 9, 20, None, None, 15, 7)
EXPECTED1 = True

ROOT2 = trees.from_values(1, 2, 2, 3, 3, None, None, 4, 4)
EXPECTED2 = False

ROOT3 = trees.from_values()
EXPECTED3 = True


class TestBalancedBinaryTree(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isBalanced(ROOT1))
        self.assertEqual(EXPECTED2, SOLUTION1.isBalanced(ROOT2))
        self.assertEqual(EXPECTED3, SOLUTION1.isBalanced(ROOT3))
