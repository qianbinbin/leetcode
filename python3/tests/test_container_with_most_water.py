from unittest import TestCase

from leetcodepy.container_with_most_water import *

solution1 = Solution1()

height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

expected = 49


class TestContainerWithMostWater(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.maxArea(height))
