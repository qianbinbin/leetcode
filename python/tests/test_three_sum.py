from unittest import TestCase

from three_sum import *

solution1 = Solution1()

nums = [-1, 0, 1, 2, -1, -4]

expected = [
    [-1, -1, 2],
    [-1, 0, 1]
]


class TestThreeSum(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.threeSum(nums))
