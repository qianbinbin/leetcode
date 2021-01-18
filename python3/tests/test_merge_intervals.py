from unittest import TestCase

from leetcodepy.merge_intervals import *
from leetcodepy.utils import Interval

solution1 = Solution1()

intervals1 = [Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)]

expected1 = [Interval(1, 6), Interval(8, 10), Interval(15, 18)]

intervals2 = [Interval(1, 4), Interval(4, 5)]

expected2 = [Interval(1, 5)]


class TestMergeIntervals(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.merge(intervals1))
        self.assertListEqual(expected2, solution1.merge(intervals2))
