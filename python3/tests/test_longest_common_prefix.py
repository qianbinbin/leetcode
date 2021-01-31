from unittest import TestCase

from leetcodepy.longest_common_prefix import *

SOLUTION1 = Solution1()

STRS1 = ["flower", "flow", "flight"]
EXPECTED1 = "fl"

STRS2 = ["dog", "racecar", "car"]
EXPECTED2 = ""


class TestLongestCommonPrefix(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.longestCommonPrefix(STRS1))
        self.assertEqual(EXPECTED2, SOLUTION1.longestCommonPrefix(STRS2))
