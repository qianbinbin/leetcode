from unittest import TestCase

from leetcodepy.merge_intervals import *

SOLUTION1 = Solution1()

INTERVALS1 = [[1, 3], [2, 6], [8, 10], [15, 18]]
EXPECTED1 = [[1, 6], [8, 10], [15, 18]]

INTERVALS2 = [[1, 4], [4, 5]]
EXPECTED2 = [[1, 5]]


class TestMergeIntervals(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.merge(INTERVALS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.merge(INTERVALS2))
