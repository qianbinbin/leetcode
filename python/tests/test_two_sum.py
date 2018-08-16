from unittest import TestCase

from leetcodepy.two_sum import *

solution1 = Solution1()

nums = [2, 7, 11, 15]

target = 9

expected = [0, 1]


class TestTwoSum(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.twoSum(nums, target))
