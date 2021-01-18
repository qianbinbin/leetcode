from unittest import TestCase

from leetcodepy.search_in_rotated_sorted_array_ii import *

solution1 = Solution1()

nums1 = [2, 5, 6, 0, 0, 1, 2]

target1 = 0

nums2 = [2, 5, 6, 0, 0, 1, 2]

target2 = 3


class TestSearchInRotatedSortedArrayII(TestCase):
    def test1(self):
        self.assertTrue(solution1.search(nums1, target1))
        self.assertFalse(solution1.search(nums2, target2))
