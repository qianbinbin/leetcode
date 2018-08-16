from unittest import TestCase

from leetcodepy.longest_substring_without_repeating_characters import *

solution1 = Solution1()

s1 = "abcabcbb"

expected1 = 3

s2 = "bbbbb"

expected2 = 1

s3 = "pwwkew"

expected3 = 3


class TestLongestSubstringWithoutRepeatingCharacters(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.lengthOfLongestSubstring(s1))
        self.assertEqual(expected2, solution1.lengthOfLongestSubstring(s2))
        self.assertEqual(expected3, solution1.lengthOfLongestSubstring(s3))
