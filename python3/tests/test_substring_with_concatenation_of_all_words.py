from unittest import TestCase

from leetcodepy.substring_with_concatenation_of_all_words import *

SOLUTION1 = Solution1()

S1 = "barfoothefoobarman"
WORDS1 = ["foo", "bar"]
EXPECTED1 = [0, 9]

S2 = "wordgoodgoodgoodbestword"
WORDS2 = ["word", "good", "best", "word"]
EXPECTED2 = []

S3 = "barfoofoobarthefoobarman"
WORDS3 = ["bar", "foo", "the"]
EXPECTED3 = [6, 9, 12]


class TestSubstringWithConcatenationOfAllWords(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.findSubstring(S1, WORDS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.findSubstring(S2, WORDS2))
        self.assertListEqual(EXPECTED3, SOLUTION1.findSubstring(S3, WORDS3))
