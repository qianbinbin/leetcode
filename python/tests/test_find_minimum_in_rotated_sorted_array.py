from unittest import TestCase

from leetcodepy.find_minimum_in_rotated_sorted_array import *

solution1 = Solution1()

nums1 = [3, 4, 5, 1, 2]

expected1 = 1

nums2 = [4, 5, 6, 7, 0, 1, 2]

expected2 = 0


class TestFindMinimumInRotatedSortedArray(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.findMin(nums1))
        self.assertEqual(expected2, solution1.findMin(nums2))
