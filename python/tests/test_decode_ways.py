from unittest import TestCase

from leetcodepy.decode_ways import *

solution1 = Solution1()

s1 = "12"

expected1 = 2

s2 = "226"

expected2 = 3


class TestDecodeWays(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.numDecodings(s1))
        self.assertEqual(expected2, solution1.numDecodings(s2))
