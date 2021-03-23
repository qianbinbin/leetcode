from unittest import TestCase

from leetcodepy.search_in_rotated_sorted_array import *

SOLUTION1 = Solution1()

NUMS1 = [4, 5, 6, 7, 0, 1, 2]
TARGET1 = 0
EXPECTED1 = 4

NUMS2 = [4, 5, 6, 7, 0, 1, 2]
TARGET2 = 3
EXPECTED2 = -1

NUMS3 = [1]
TARGET3 = 0
EXPECTED3 = -1


class TestSearchInRotatedSortedArray(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.search(NUMS1, TARGET1))
        self.assertEqual(EXPECTED2, SOLUTION1.search(NUMS2, TARGET2))
        self.assertEqual(EXPECTED3, SOLUTION1.search(NUMS3, TARGET3))
