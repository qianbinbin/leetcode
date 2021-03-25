from unittest import TestCase

from leetcodepy.search_insert_position import *

SOLUTION1 = Solution1()

NUMS1 = [1, 3, 5, 6]
TARGET1 = 5
EXPECTED1 = 2

NUMS2 = [1, 3, 5, 6]
TARGET2 = 2
EXPECTED2 = 1

NUMS3 = [1, 3, 5, 6]
TARGET3 = 7
EXPECTED3 = 4

NUMS4 = [1, 3, 5, 6]
TARGET4 = 0
EXPECTED4 = 0

NUMS5 = [1]
TARGET5 = 0
EXPECTED5 = 0


class TestSearchInsertPosition(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.searchInsert(NUMS1, TARGET1))
        self.assertEqual(EXPECTED2, SOLUTION1.searchInsert(NUMS2, TARGET2))
        self.assertEqual(EXPECTED3, SOLUTION1.searchInsert(NUMS3, TARGET3))
        self.assertEqual(EXPECTED4, SOLUTION1.searchInsert(NUMS4, TARGET4))
        self.assertEqual(EXPECTED5, SOLUTION1.searchInsert(NUMS5, TARGET5))
