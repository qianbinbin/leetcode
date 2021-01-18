from unittest import TestCase

from leetcodepy.convert_sorted_list_to_binary_search_tree import *
from leetcodepy.utils import linked_lists, trees

solution1 = Solution1()

head = linked_lists.from_values(-10, -3, 0, 5, 9)

expected = trees.from_values(0, -3, 9, -10, None, 5)


class TestConvertSortedListToBinarySearchTree(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(expected, solution1.sortedListToBST(head)))
