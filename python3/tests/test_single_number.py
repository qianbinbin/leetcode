from unittest import TestCase

from leetcodepy.single_number import *

SOLUTION1 = Solution1()

NUMS1 = [2, 2, 1]
EXPECTED1 = 1

NUMS2 = [4, 1, 2, 1, 2]
EXPECTED2 = 4

NUMS3 = [1]
EXPECTED3 = 1


class TestSingleNumber(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.singleNumber(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.singleNumber(NUMS2))
        self.assertEqual(EXPECTED3, SOLUTION1.singleNumber(NUMS3))
