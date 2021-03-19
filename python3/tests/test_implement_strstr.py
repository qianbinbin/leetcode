from unittest import TestCase

from leetcodepy.implement_strstr import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

HAYSTACK1 = "hello"
NEEDLE1 = "ll"
EXPECTED1 = 2

HAYSTACK2 = "aaaaa"
NEEDLE2 = "bba"
EXPECTED2 = -1

HAYSTACK3 = ""
NEEDLE3 = ""
EXPECTED3 = 0


class TestImplementStrStr(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.strStr(HAYSTACK1, NEEDLE1))
        self.assertEqual(EXPECTED2, SOLUTION1.strStr(HAYSTACK2, NEEDLE2))
        self.assertEqual(EXPECTED3, SOLUTION1.strStr(HAYSTACK3, NEEDLE3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.strStr(HAYSTACK1, NEEDLE1))
        self.assertEqual(EXPECTED2, SOLUTION2.strStr(HAYSTACK2, NEEDLE2))
        self.assertEqual(EXPECTED3, SOLUTION2.strStr(HAYSTACK3, NEEDLE3))
