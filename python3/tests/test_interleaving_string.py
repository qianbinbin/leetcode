from unittest import TestCase

from leetcodepy.interleaving_string import *

SOLUTION1 = Solution1()

S11 = "aabcc"
S12 = "dbbca"
S13 = "aadbbcbcac"
EXPECTED1 = True

S21 = "aabcc"
S22 = "dbbca"
S23 = "aadbbbaccc"
EXPECTED2 = False

S31 = ""
S32 = ""
S33 = ""
EXPECTED3 = True


class TestInterleavingString(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isInterleave(S11, S12, S13))
        self.assertEqual(EXPECTED2, SOLUTION1.isInterleave(S21, S22, S33))
        self.assertEqual(EXPECTED3, SOLUTION1.isInterleave(S31, S32, S33))
