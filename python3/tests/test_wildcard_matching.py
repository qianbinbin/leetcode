from unittest import TestCase

from leetcodepy.wildcard_matching import *

solution1 = Solution1()

solution2 = Solution2()

s1 = "aa"

p1 = "a"

s2 = "aa"

p2 = "*"

s3 = "cb"

p3 = "?a"

s4 = "adceb"

p4 = "*a*b"

s5 = "acdcb"

p5 = "a*c?b"


class TestWildcardMatching(TestCase):
    def test1(self):
        self.assertFalse(solution1.isMatch(s1, p1))
        self.assertTrue(solution1.isMatch(s2, p2))
        self.assertFalse(solution1.isMatch(s3, p3))
        self.assertTrue(solution1.isMatch(s4, p4))
        self.assertFalse(solution1.isMatch(s5, p5))

    def test2(self):
        self.assertFalse(solution2.isMatch(s1, p1))
        self.assertTrue(solution2.isMatch(s2, p2))
        self.assertFalse(solution2.isMatch(s3, p3))
        self.assertTrue(solution2.isMatch(s4, p4))
        self.assertFalse(solution2.isMatch(s5, p5))
