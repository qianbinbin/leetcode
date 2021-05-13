from unittest import TestCase

from leetcodepy.wildcard_matching import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S1 = "aa"
P1 = "a"
EXPECTED1 = False

S2 = "aa"
P2 = "*"
EXPECTED2 = True

S3 = "cb"
P3 = "?a"
EXPECTED3 = False

S4 = "adceb"
P4 = "*a*b"
EXPECTED4 = True

S5 = "acdcb"
P5 = "a*c?b"
EXPECTED5 = False


class TestWildcardMatching(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isMatch(S1, P1))
        self.assertEqual(EXPECTED2, SOLUTION1.isMatch(S2, P2))
        self.assertEqual(EXPECTED3, SOLUTION1.isMatch(S3, P3))
        self.assertEqual(EXPECTED4, SOLUTION1.isMatch(S4, P4))
        self.assertEqual(EXPECTED5, SOLUTION1.isMatch(S5, P5))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.isMatch(S1, P1))
        self.assertEqual(EXPECTED2, SOLUTION2.isMatch(S2, P2))
        self.assertEqual(EXPECTED3, SOLUTION2.isMatch(S3, P3))
        self.assertEqual(EXPECTED4, SOLUTION2.isMatch(S4, P4))
        self.assertEqual(EXPECTED5, SOLUTION2.isMatch(S5, P5))
