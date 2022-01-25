from unittest import TestCase

from leetcodepy.largest_rectangle_in_histogram import *

SOLUTION1 = Solution1()

HEIGHTS1 = [2, 1, 5, 6, 2, 3]
EXPECTED1 = 10

HEIGHTS2 = [2, 4]
EXPECTED2 = 4


class TestLargestRectangleInHistogram(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.largestRectangleArea(HEIGHTS1))
        self.assertEqual(EXPECTED2, SOLUTION1.largestRectangleArea(HEIGHTS2))
