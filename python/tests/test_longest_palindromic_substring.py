from unittest import TestCase

from leetcodepy.longest_palindromic_substring import *

solution1 = Solution1()

s1 = "babad"

expected1 = "aba"

s2 = "cbbd"

expected2 = "bb"


class TestLongestPalindromicSubstring(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.longestPalindrome(s1))
        self.assertEqual(expected2, solution1.longestPalindrome(s2))
