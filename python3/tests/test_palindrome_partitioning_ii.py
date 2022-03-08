from unittest import TestCase

from leetcodepy.palindrome_partitioning_ii import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S1 = "aab"
EXPECTED1 = 1

S2 = "a"
EXPECTED2 = 0

S3 = "ab"
EXPECTED3 = 1


class TestPalindromePartitioningII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minCut(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.minCut(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.minCut(S3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.minCut(S1))
        self.assertEqual(EXPECTED2, SOLUTION2.minCut(S2))
        self.assertEqual(EXPECTED3, SOLUTION2.minCut(S3))
