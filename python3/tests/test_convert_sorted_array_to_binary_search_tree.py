from unittest import TestCase

from leetcodepy.convert_sorted_array_to_binary_search_tree import *
from leetcodepy.utils import trees

solution1 = Solution1()

nums = [-10, -3, 0, 5, 9]

expected = trees.from_values(0, -3, 9, -10, None, 5)


class TestConvertSortedArrayToBinarySearchTree(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(expected, solution1.sortedArrayToBST(nums)))
