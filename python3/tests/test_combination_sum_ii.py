from unittest import TestCase

from leetcodepy.combination_sum_ii import *

solution1 = Solution1()

candidates1 = [10, 1, 2, 7, 6, 1, 5]

target1 = 8

expected1 = [
    [1, 1, 6],
    [1, 2, 5],
    [1, 7],
    [2, 6]
]

candidates2 = [2, 5, 2, 1, 2]

target2 = 5

expected2 = [
    [1, 2, 2],
    [5]
]


class TestCombinationSumII(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.combinationSum2(candidates1, target1))
        self.assertListEqual(expected2, solution1.combinationSum2(candidates2, target2))
