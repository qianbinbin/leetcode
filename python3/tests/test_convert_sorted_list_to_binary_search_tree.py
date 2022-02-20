from unittest import TestCase

from leetcodepy.convert_sorted_list_to_binary_search_tree import *
from leetcodepy.utils import linked_lists, trees

SOLUTION1 = Solution1()

HEAD1 = linked_lists.from_values(-10, -3, 0, 5, 9)
EXPECTED1 = trees.from_values(0, -3, 9, -10, None, 5)

HEAD2 = linked_lists.from_values()
EXPECTED2 = trees.from_values()


class TestConvertSortedListToBinarySearchTree(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(EXPECTED1, SOLUTION1.sortedListToBST(HEAD1)))
        self.assertTrue(trees.equals(EXPECTED2, SOLUTION1.sortedListToBST(HEAD2)))
