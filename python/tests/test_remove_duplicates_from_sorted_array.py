from unittest import TestCase

from leetcodepy.remove_duplicates_from_sorted_array import *

solution1 = Solution1()

expected1 = [1, 2]

expected2 = [0, 1, 2, 3, 4]


class TestRemoveDuplicatesFromSortedArray(TestCase):
    def test1(self):
        nums1 = [1, 1, 2]
        size1 = solution1.removeDuplicates(nums1)
        self.assertListEqual(expected1, nums1[:size1])

        nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
        size2 = solution1.removeDuplicates(nums2)
        self.assertListEqual(expected2, nums2[:size2])
