from unittest import TestCase

from leetcodepy.convert_sorted_array_to_binary_search_tree import *
from leetcodepy.utils import trees

SOLUTION1 = Solution1()

NUMS1 = [-10, -3, 0, 5, 9]
EXPECTED1 = trees.from_values(0, -3, 9, -10, None, 5)

NUMS2 = [1, 3]
EXPECTED2 = trees.from_values(3, 1)


class TestConvertSortedArrayToBinarySearchTree(TestCase):
    def test1(self):
        self.assertTrue(trees.equals(EXPECTED1, SOLUTION1.sortedArrayToBST(NUMS1)))
        self.assertTrue(trees.equals(EXPECTED2, SOLUTION1.sortedArrayToBST(NUMS2)))
