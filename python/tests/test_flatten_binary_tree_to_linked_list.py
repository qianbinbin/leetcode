from unittest import TestCase

from leetcodepy.flatten_binary_tree_to_linked_list import *
from leetcodepy.utils import trees

solution1 = Solution1()

values = (1, 2, 5, 3, 4, None, 6)

expected = trees.from_values(1, None, 2, None, 3, None, 4, None, 5, None, 6)


class TestFlattenBinaryTreeToLinkedList(TestCase):
    def test1(self):
        root = trees.from_values(*values)
        solution1.flatten(root)
        self.assertTrue(trees.equals(expected, root))
