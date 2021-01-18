from unittest import TestCase

from leetcodepy.interleaving_string import *

solution1 = Solution1()

s11 = "aabcc"

s12 = "dbbca"

s13 = "aadbbcbcac"

s21 = "aabcc"

s22 = "dbbca"

s23 = "aadbbbaccc"


class TestInterleavingString(TestCase):
    def test1(self):
        self.assertTrue(solution1.isInterleave(s11, s12, s13))
        self.assertFalse(solution1.isInterleave(s21, s22, s23))
