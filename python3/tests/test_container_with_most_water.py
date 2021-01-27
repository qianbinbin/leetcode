from unittest import TestCase

from leetcodepy.container_with_most_water import *

SOLUTION1 = Solution1()

HEIGHT1 = [1, 8, 6, 2, 5, 4, 8, 3, 7]
EXPECTED1 = 49

HEIGHT2 = [1, 1]
EXPECTED2 = 1

HEIGHT3 = [4, 3, 2, 1, 4]
EXPECTED3 = 16

HEIGHT4 = [1, 2, 1]
EXPECTED4 = 2


class TestContainerWithMostWater(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxArea(HEIGHT1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxArea(HEIGHT2))
        self.assertEqual(EXPECTED3, SOLUTION1.maxArea(HEIGHT3))
        self.assertEqual(EXPECTED4, SOLUTION1.maxArea(HEIGHT4))
