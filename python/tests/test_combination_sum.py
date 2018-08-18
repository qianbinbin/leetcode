from unittest import TestCase

from leetcodepy.combination_sum import *

solution1 = Solution1()

candidates1 = [2, 3, 6, 7]

target1 = 7

expected1 = [
    [2, 2, 3],
    [7]
]

candidates2 = [2, 3, 5]

target2 = 8

expected2 = [
    [2, 2, 2, 2],
    [2, 3, 3],
    [3, 5]
]


class TestCombinationSum(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.combinationSum(candidates1, target1))
        self.assertListEqual(expected2, solution1.combinationSum(candidates2, target2))
