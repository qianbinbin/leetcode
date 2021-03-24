from unittest import TestCase

from leetcodepy.find_first_and_last_position_of_element_in_sorted_array import *

SOLUTION1 = Solution1()

NUMS1 = [5, 7, 7, 8, 8, 10]
TARGET1 = 8
EXPECTED1 = [3, 4]

NUMS2 = [5, 7, 7, 8, 8, 10]
TARGET2 = 6
EXPECTED2 = [-1, -1]

NUMS3 = []
TARGET3 = 0
EXPECTED3 = [-1, -1]


class TestFindFirstAndLastPositionOfElementInSortedArray(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.searchRange(NUMS1, TARGET1))
        self.assertListEqual(EXPECTED2, SOLUTION1.searchRange(NUMS2, TARGET2))
        self.assertListEqual(EXPECTED3, SOLUTION1.searchRange(NUMS3, TARGET3))
