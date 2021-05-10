from unittest import TestCase

from leetcodepy.first_missing_positive import *

SOLUTION1 = Solution1()

NUMS1 = [1, 2, 0]
EXPECTED1 = 3

NUMS2 = [3, 4, -1, 1]
EXPECTED2 = 2

NUMS3 = [7, 8, 9, 11, 12]
EXPECTED3 = 1


class TestFirstMissingPositive(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.firstMissingPositive(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.firstMissingPositive(NUMS2))
        self.assertEqual(EXPECTED3, SOLUTION1.firstMissingPositive(NUMS3))
