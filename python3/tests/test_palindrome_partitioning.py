from unittest import TestCase

from leetcodepy.palindrome_partitioning import *

SOLUTION1 = Solution1()

S1 = "aab"
EXPECTED1 = [
    ["a", "a", "b"],
    ["aa", "b"]
]

S2 = "a"
EXPECTED2 = [["a"]]


class TestPalindromePartitioning(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.partition(S1))
        self.assertListEqual(EXPECTED2, SOLUTION1.partition(S2))
