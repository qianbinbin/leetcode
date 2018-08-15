from unittest import TestCase

from leetcodepy.find_first_and_last_position_of_element_in_sorted_array import *

solution1 = Solution1()

nums1 = [5, 7, 7, 8, 8, 10]

target1 = 8

expected1 = [3, 4]

nums2 = [5, 7, 7, 8, 8, 10]

target2 = 6

expected2 = [-1, -1]


class TestFindFirstAndLastPositionOfElementInSortedArray(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.searchRange(nums1, target1))
        self.assertListEqual(expected2, solution1.searchRange(nums2, target2))
