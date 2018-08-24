from unittest import TestCase

from leetcodepy.single_number import *

solution1 = Solution1()

nums1 = [2, 2, 1]

expected1 = 1

nums2 = [4, 1, 2, 1, 2]

expected2 = 4


class TestSingleNumber(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.singleNumber(nums1))
        self.assertEqual(expected2, solution1.singleNumber(nums2))
