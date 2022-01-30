from unittest import TestCase

from leetcodepy.decode_ways import *

SOLUTION1 = Solution1()

S1 = "12"
EXPECTED1 = 2

S2 = "226"
EXPECTED2 = 3

S3 = "06"
EXPECTED3 = 0


class TestDecodeWays(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.numDecodings(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.numDecodings(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.numDecodings(S3))
