from unittest import TestCase

from leetcodepy.max_points_on_a_line import *
from leetcodepy.utils import Point

solution1 = Solution1()

points1 = [Point(1, 1), Point(2, 2), Point(3, 3)]

expected1 = 3

points2 = [Point(1, 1), Point(3, 2), Point(5, 3), Point(4, 1), Point(2, 3), Point(1, 4)]

expected2 = 4


class TestMaxPointsOnALine(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxPoints(points1))
        self.assertEqual(expected2, solution1.maxPoints(points2))
