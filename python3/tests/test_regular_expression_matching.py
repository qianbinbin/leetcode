from unittest import TestCase

from leetcodepy.regular_expression_matching import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S1 = "aa"
P1 = "a"
EXPECTED1 = False

S2 = "aa"
P2 = "a*"
EXPECTED2 = True

S3 = "ab"
P3 = ".*"
EXPECTED3 = True

S4 = "aab"
P4 = "c*a*b"
EXPECTED4 = True

S5 = "mississippi"
P5 = "mis*is*p*."
EXPECTED5 = False


class TestRegularExpressionMatching(TestCase):
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
