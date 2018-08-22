from unittest import TestCase

from leetcodepy.palindrome_partitioning_ii import *

solution1 = Solution1()

solution2 = Solution2()

s = "aab"

expected = 1


class TestPalindromePartitioningII(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.minCut(s))

    def test2(self):
        self.assertEqual(expected, solution2.minCut(s))
