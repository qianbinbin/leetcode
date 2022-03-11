from unittest import TestCase

from leetcodepy.single_number_ii import *

SOLUTION1 = Solution1()

NUMS1 = [2, 2, 3, 2]
EXPECTED1 = 3

NUMS2 = [0, 1, 0, 1, 0, 1, 99]
EXPECTED2 = 99


class TestSingleNumberII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.singleNumber(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.singleNumber(NUMS2))
