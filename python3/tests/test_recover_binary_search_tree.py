from unittest import TestCase

from leetcodepy.recover_binary_search_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()


def ROOT1():
    return trees.from_values(1, 3, None, None, 2)


EXPECTED1 = trees.from_values(3, 1, None, None, 2)


def ROOT2():
    return trees.from_values(3, 1, 4, None, None, 2)


EXPECTED2 = trees.from_values(2, 1, 4, None, None, 3)


class TestRecoverBinarySearchTree(TestCase):
    def test1(self):
        root1 = ROOT1()
        SOLUTION1.recoverTree(root1)
        self.assertTrue(trees.equals(EXPECTED1, root1))

        root2 = ROOT2()
        SOLUTION1.recoverTree(root2)
        self.assertTrue(trees.equals(EXPECTED2, root2))
