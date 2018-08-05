from unittest import TestCase

from find_minimum_in_rotated_sorted_array_ii import *

solution1 = Solution1()

nums1 = [1, 3, 5]

expected1 = 1

nums2 = [2, 2, 2, 0, 1]

expected2 = 0


class TestFindMinimumInRotatedSortedArrayII(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.findMin(nums1))
        self.assertEqual(expected2, solution1.findMin(nums2))
