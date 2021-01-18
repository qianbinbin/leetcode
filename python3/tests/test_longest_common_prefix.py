from unittest import TestCase

from leetcodepy.longest_common_prefix import *

solution1 = Solution1()

strs1 = ["flower", "flow", "flight"]

expected1 = "fl"

strs2 = ["dog", "racecar", "car"]

expected2 = ""


class TestLongestCommonPrefix(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.longestCommonPrefix(strs1))
        self.assertEqual(expected2, solution1.longestCommonPrefix(strs2))
