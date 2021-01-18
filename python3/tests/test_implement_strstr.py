from unittest import TestCase

from leetcodepy.implement_strstr import *

solution1 = Solution1()

solution2 = Solution2()

haystack1 = "hello"

needle1 = "ll"

expected1 = 2

haystack2 = "aaaaa"

needle2 = "bba"

expected2 = -1


class TestImplementStrStr(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.strStr(haystack1, needle1))
        self.assertEqual(expected2, solution1.strStr(haystack2, needle2))

    def test2(self):
        self.assertEqual(expected1, solution2.strStr(haystack1, needle1))
        self.assertEqual(expected2, solution2.strStr(haystack2, needle2))
