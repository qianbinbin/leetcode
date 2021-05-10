from unittest import TestCase

from leetcodepy.combination_sum import *

SOLUTION1 = Solution1()

CANDIDATES1 = [2, 3, 6, 7]
TARGET1 = 7
EXPECTED1 = [[2, 2, 3], [7]]

CANDIDATES2 = [2, 3, 5]
TARGET2 = 8
EXPECTED2 = [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

CANDIDATES3 = [2]
TARGET3 = 1
EXPECTED3 = []

CANDIDATES4 = [1]
TARGET4 = 1
EXPECTED4 = [[1]]

CANDIDATES5 = [1]
TARGET5 = 2
EXPECTED5 = [[1, 1]]


class TestCombinationSum(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.combinationSum(CANDIDATES1, TARGET1))
        self.assertListEqual(EXPECTED2, SOLUTION1.combinationSum(CANDIDATES2, TARGET2))
        self.assertListEqual(EXPECTED3, SOLUTION1.combinationSum(CANDIDATES3, TARGET3))
        self.assertListEqual(EXPECTED4, SOLUTION1.combinationSum(CANDIDATES4, TARGET4))
        self.assertListEqual(EXPECTED5, SOLUTION1.combinationSum(CANDIDATES5, TARGET5))
