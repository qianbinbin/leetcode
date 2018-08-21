from unittest import TestCase

from leetcodepy.regular_expression_matching import *

solution1 = Solution1()

s1 = "aa"

p1 = "a"

s2 = "aa"

p2 = "a*"

s3 = "ab"

p3 = ".*"

s4 = "aab"

p4 = "c*a*b"

s5 = "mississippi"

p5 = "mis*is*p*."


class TestRegularExpressionMatching(TestCase):
    def test1(self):
        self.assertFalse(solution1.isMatch(s1, p1))
        self.assertTrue(solution1.isMatch(s2, p2))
        self.assertTrue(solution1.isMatch(s3, p3))
        self.assertTrue(solution1.isMatch(s4, p4))
        self.assertFalse(solution1.isMatch(s5, p5))
