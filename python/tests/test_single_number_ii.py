from unittest import TestCase

from leetcodepy.single_number_ii import *

solution1 = Solution1()

nums1 = [2, 2, 3, 2]

expected1 = 3

nums2 = [0, 1, 0, 1, 0, 1, 99]

expected2 = 99


class TestSingleNumberII(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.singleNumber(nums1))
        self.assertEqual(expected2, solution1.singleNumber(nums2))
