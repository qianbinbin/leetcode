from unittest import TestCase

from leetcodepy.climbing_stairs import *

SOLUTION1 = Solution1()

N1 = 2
EXPECTED1 = 2

N2 = 3
EXPECTED2 = 3


class TestClimbingStairs(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.climbStairs(N1))
        self.assertEqual(EXPECTED2, SOLUTION1.climbStairs(N2))
