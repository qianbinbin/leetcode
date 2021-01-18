from unittest import TestCase

from leetcodepy.maximum_subarray import *

solution1 = Solution1()

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

expected = 6


class TestMaximumSubarray(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.maxSubArray(nums))
