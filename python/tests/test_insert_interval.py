from unittest import TestCase

from leetcodepy.insert_interval import *
from leetcodepy.utils import Interval

solution1 = Solution1()

intervals1 = [Interval(1, 3), Interval(6, 9)]

newInterval1 = Interval(2, 5)

expected1 = [Interval(1, 5), Interval(6, 9)]

intervals2 = [Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)]

newInterval2 = Interval(4, 8)

expected2 = [Interval(1, 2), Interval(3, 10), Interval(12, 16)]


class TestInsertInterval(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.insert(intervals1, newInterval1))
        self.assertListEqual(expected2, solution1.insert(intervals2, newInterval2))
