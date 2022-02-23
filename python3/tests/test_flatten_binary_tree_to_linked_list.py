from unittest import TestCase

from leetcodepy.flatten_binary_tree_to_linked_list import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()


def ROOT1():
    return trees.from_values(1, 2, 5, 3, 4, None, 6)


EXPECTED1 = trees.from_values(1, None, 2, None, 3, None, 4, None, 5, None, 6)


def ROOT2():
    return trees.from_values()


EXPECTED2 = trees.from_values()


def ROOT3():
    return trees.from_values(0)


EXPECTED3 = trees.from_values(0)


class TestFlattenBinaryTreeToLinkedList(TestCase):
    def test1(self):
        root1 = ROOT1()
        SOLUTION1.flatten(root1)
        self.assertTrue(trees.equals(EXPECTED1, root1))

        root2 = ROOT2()
        SOLUTION1.flatten(root2)
        self.assertTrue(trees.equals(EXPECTED2, root2))

        root3 = ROOT3()
        SOLUTION1.flatten(root3)
        self.assertTrue(trees.equals(EXPECTED3, root3))

    def test2(self):
        root1 = ROOT1()
        SOLUTION2.flatten(root1)
        self.assertTrue(trees.equals(EXPECTED1, root1))

        root2 = ROOT2()
        SOLUTION2.flatten(root2)
        self.assertTrue(trees.equals(EXPECTED2, root2))

        root3 = ROOT3()
        SOLUTION2.flatten(root3)
        self.assertTrue(trees.equals(EXPECTED3, root3))
