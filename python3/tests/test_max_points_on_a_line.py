from unittest import TestCase

from leetcodepy.max_points_on_a_line import *

SOLUTION1 = Solution1()

S1 = [[1, 1], [2, 2], [3, 3]]
EXPECTED1 = 3

S2 = [[1, 1], [3, 2], [5, 3], [4, 1], [2, 3], [1, 4]]
EXPECTED2 = 4


class TestMaxPointsOnALine(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxPoints(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxPoints(S2))
