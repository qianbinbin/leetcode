from unittest import TestCase

from leetcodepy.longest_palindromic_substring import *

SOLUTION1 = Solution1()

S1 = "babad"
EXPECTED1 = "bab"

S2 = "cbbd"
EXPECTED2 = "bb"

S3 = "a"
EXPECTED3 = "a"

S4 = "ac"
EXPECTED4 = "a"


class TestLongestPalindromicSubstring(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.longestPalindrome(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.longestPalindrome(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.longestPalindrome(S3))
        self.assertEqual(EXPECTED4, SOLUTION1.longestPalindrome(S4))
