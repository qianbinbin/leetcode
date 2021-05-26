from unittest import TestCase

from leetcodepy.maximum_subarray import *

SOLUTION1 = Solution1()

NUMS1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
EXPECTED1 = 6

NUMS2 = [1]
EXPECTED2 = 1

NUMS3 = [5, 4, -1, 7, 8]
EXPECTED3 = 23


class TestMaximumSubarray(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxSubArray(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxSubArray(NUMS2))
        self.assertEqual(EXPECTED3, SOLUTION1.maxSubArray(NUMS3))
