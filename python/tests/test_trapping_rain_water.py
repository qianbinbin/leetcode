from unittest import TestCase

from trapping_rain_water import *

solution1 = Solution1()

height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

expected = 6


class TestTrappingRainWater(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.trap(height))
