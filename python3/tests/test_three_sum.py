from unittest import TestCase

from leetcodepy.three_sum import *

SOLUTION1 = Solution1()

NUMS1 = [-1, 0, 1, 2, -1, -4]
EXPECTED1 = [[-1, -1, 2], [-1, 0, 1]]

NUMS2 = []
EXPECTED2 = []

NUMS3 = [0]
EXPECTED3 = []


class TestThreeSum(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.threeSum(NUMS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.threeSum(NUMS2))
        self.assertListEqual(EXPECTED3, SOLUTION1.threeSum(NUMS3))
