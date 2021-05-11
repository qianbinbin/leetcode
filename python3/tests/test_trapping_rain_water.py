from unittest import TestCase

from leetcodepy.trapping_rain_water import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()
SOLUTION3 = Solution3()

HEIGHT1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
EXPECTED1 = 6

HEIGHT2 = [4, 2, 0, 3, 2, 5]
EXPECTED2 = 9


class TestTrappingRainWater(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.trap(HEIGHT1))
        self.assertEqual(EXPECTED2, SOLUTION1.trap(HEIGHT2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.trap(HEIGHT1))
        self.assertEqual(EXPECTED2, SOLUTION2.trap(HEIGHT2))

    def test3(self):
        self.assertEqual(EXPECTED1, SOLUTION3.trap(HEIGHT1))
        self.assertEqual(EXPECTED2, SOLUTION3.trap(HEIGHT2))
