from unittest import TestCase

from leetcodepy.search_in_rotated_sorted_array_ii import *

SOLUTION1 = Solution1()

NUMS1 = [2, 5, 6, 0, 0, 1, 2]
TARGET1 = 0
EXPECTED1 = True

NUMS2 = [2, 5, 6, 0, 0, 1, 2]
TARGET2 = 3
EXPECTED2 = False


class TestSearchInRotatedSortedArrayII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.search(NUMS1, TARGET1))
        self.assertEqual(EXPECTED2, SOLUTION1.search(NUMS2, TARGET2))
