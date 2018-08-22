from unittest import TestCase

from leetcodepy.distinct_subsequences import *

solution1 = Solution1()

s1 = "rabbbit"

t1 = "rabbit"

expected1 = 3

s2 = "babgbag"

t2 = "bag"

expected2 = 5


class TestDistinctSubsequences(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.numDistinct(s1, t1))
        self.assertEqual(expected2, solution1.numDistinct(s2, t2))
