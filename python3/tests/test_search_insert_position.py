from unittest import TestCase

from leetcodepy.search_insert_position import *

solution1 = Solution1()

nums1 = [1, 3, 5, 6]

target1 = 5

expected1 = 2

nums2 = [1, 3, 5, 6]

target2 = 2

expected2 = 1

nums3 = [1, 3, 5, 6]

target3 = 7

expected3 = 4

nums4 = [1, 3, 5, 6]

target4 = 0

expected4 = 0


class TestSearchInsertPosition(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.searchInsert(nums1, target1))
        self.assertEqual(expected2, solution1.searchInsert(nums2, target2))
        self.assertEqual(expected3, solution1.searchInsert(nums3, target3))
        self.assertEqual(expected4, solution1.searchInsert(nums4, target4))
