from unittest import TestCase

from merge_sorted_array import *

solution1 = Solution1()

expected = [1, 2, 2, 3, 5, 6]


class TestMergeSortedArray(TestCase):
    def test1(self):
        nums1 = [1, 2, 3, 0, 0, 0]
        nums2 = [2, 5, 6]
        solution1.merge(nums1, 3, nums2, 3)
        self.assertListEqual(expected, nums1)
