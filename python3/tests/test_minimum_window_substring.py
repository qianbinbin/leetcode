from unittest import TestCase

from leetcodepy.minimum_window_substring import *

SOLUTION1 = Solution1()

S1 = "ADOBECODEBANC"
T1 = "ABC"
EXPECTED1 = "BANC"

S2 = "a"
T2 = "a"
EXPECTED2 = "a"

S3 = "a"
T3 = "aa"
EXPECTED3 = ""


class TestMinimumWindowSubstring(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minWindow(S1, T1))
        self.assertEqual(EXPECTED2, SOLUTION1.minWindow(S2, T2))
        self.assertEqual(EXPECTED3, SOLUTION1.minWindow(S3, T3))
