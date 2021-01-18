from unittest import TestCase

from leetcodepy.two_sum import *

SOLUTION1 = Solution1()

NUMS1 = [2, 7, 11, 15]
TARGET1 = 9
EXPECTED1 = [0, 1]

NUMS2 = [3, 2, 4]
TARGET2 = 6
EXPECTED2 = [1, 2]

NUMS3 = [3, 3]
TARGET3 = 6
EXPECTED3 = [0, 1]


class TestTwoSum(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.twoSum(NUMS1, TARGET1))
        self.assertListEqual(EXPECTED2, SOLUTION1.twoSum(NUMS2, TARGET2))
        self.assertListEqual(EXPECTED3, SOLUTION1.twoSum(NUMS3, TARGET3))
