from unittest import TestCase

from leetcodepy.palindrome_partitioning import *

solution1 = Solution1()

s = "aab"

expected = [
    ["a", "a", "b"],
    ["aa", "b"]
]


class TestPalindromePartitioning(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.partition(s))
