from unittest import TestCase

from leetcodepy.climbing_stairs import *

solution1 = Solution1()

n1 = 2

expected1 = 2

n2 = 3

expected2 = 3


class TestClimbingStairs(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.climbStairs(n1))
        self.assertEqual(expected2, solution1.climbStairs(n2))
