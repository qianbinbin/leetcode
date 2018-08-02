from unittest import TestCase

from maximum_product_subarray import *

solution1 = Solution1()

nums1 = [2, 3, -2, 4]

expected1 = 6

nums2 = [-2, 0, -1]

expected2 = 0


class TestMaximumProductSubarray(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxProduct(nums1))
        self.assertEqual(expected2, solution1.maxProduct(nums2))
