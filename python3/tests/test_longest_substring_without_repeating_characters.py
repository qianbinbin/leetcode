from unittest import TestCase

from leetcodepy.longest_substring_without_repeating_characters import *

SOLUTION1 = Solution1()

S1 = "abcabcbb"
EXPECTED1 = 3

S2 = "bbbbb"
EXPECTED2 = 1

S3 = "pwwkew"
EXPECTED3 = 3

S4 = ""
EXPECTED4 = 0


class TestLongestSubstringWithoutRepeatingCharacters(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.lengthOfLongestSubstring(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.lengthOfLongestSubstring(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.lengthOfLongestSubstring(S3))
        self.assertEqual(EXPECTED4, SOLUTION1.lengthOfLongestSubstring(S4))
