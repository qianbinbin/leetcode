from unittest import TestCase

from leetcodepy.distinct_subsequences import *

SOLUTION1 = Solution1()

S1 = "rabbbit"
T1 = "rabbit"
EXPECTED1 = 3

S2 = "babgbag"
T2 = "bag"
EXPECTED2 = 5


class TestDistinctSubsequences(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.numDistinct(S1, T1))
        self.assertEqual(EXPECTED2, SOLUTION1.numDistinct(S2, T2))
