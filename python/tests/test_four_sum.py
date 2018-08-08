from unittest import TestCase

from leetcodepy.four_sum import *

solution1 = Solution1()

solution2 = Solution2()

nums = [1, 0, -1, 0, -2, 2]

target = 0

expected = [
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1]
]


class TestFourSum(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.fourSum(nums, target))

    def test2(self):
        self.assertListEqual(expected, solution2.fourSum(nums, target))
