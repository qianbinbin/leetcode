from unittest import TestCase

from leetcodepy.minimum_window_substring import *

solution1 = Solution1()

s = "ADOBECODEBANC"

t = "ABC"

expected = "BANC"


class TestMinimumWindowSubstring(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.minWindow(s, t))
