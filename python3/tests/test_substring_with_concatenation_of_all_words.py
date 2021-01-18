from unittest import TestCase

from leetcodepy.substring_with_concatenation_of_all_words import *

solution1 = Solution1()

s1 = "barfoothefoobarman"

words1 = ["foo", "bar"]

expected1 = [0, 9]

s2 = "wordgoodstudentgoodword"

words2 = ["word", "student"]

expected2 = []


class TestSubstringWithConcatenationOfAllWords(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.findSubstring(s1, words1))
        self.assertListEqual(expected2, solution1.findSubstring(s2, words2))
