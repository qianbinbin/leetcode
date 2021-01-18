from unittest import TestCase

from leetcodepy.largest_rectangle_in_histogram import *

solution1 = Solution1()

heights = [2, 1, 5, 6, 2, 3]

expected = 10


class TestLargestRectangleInHistogram(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.largestRectangleArea(heights))
