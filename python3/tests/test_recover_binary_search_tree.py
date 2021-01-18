from unittest import TestCase

from leetcodepy.recover_binary_search_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

values1 = (1, 3, None, None, 2)

expected1 = trees.from_values(3, 1, None, None, 2)

values2 = (3, 1, 4, None, None, 2)

expected2 = trees.from_values(2, 1, 4, None, None, 3)


class TestRecoverBinarySearchTree(TestCase):
    def test1(self):
        root1 = trees.from_values(*values1)
        solution1.recoverTree(root1)
        self.assertTrue(trees.equals(expected1, root1))

        root2 = trees.from_values(*values2)
        solution1.recoverTree(root2)
        self.assertTrue(trees.equals(expected2, root2))
