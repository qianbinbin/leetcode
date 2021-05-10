from unittest import TestCase

from leetcodepy.combination_sum_ii import *

SOLUTION1 = Solution1()

CANDIDATES1 = [10, 1, 2, 7, 6, 1, 5]
TARGET1 = 8
EXPECTED1 = [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]

CANDIDATES2 = [2, 5, 2, 1, 2]
TARGET2 = 5
EXPECTED2 = [[1, 2, 2], [5]]


class TestCombinationSumII(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.combinationSum2(CANDIDATES1, TARGET1))
        self.assertListEqual(EXPECTED2, SOLUTION1.combinationSum2(CANDIDATES2, TARGET2))
