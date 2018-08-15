from unittest import TestCase

from leetcodepy.search_in_rotated_sorted_array import *

solution1 = Solution1()

nums1 = [4, 5, 6, 7, 0, 1, 2]

target1 = 0

expected1 = 4

nums2 = [4, 5, 6, 7, 0, 1, 2]

target2 = 3

expected2 = -1


class TestSearchInRotatedSortedArray(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.search(nums1, target1))
        self.assertEqual(expected2, solution1.search(nums2, target2))
