from unittest import TestCase

from leetcodepy.word_break_ii import *

SOLUTION1 = Solution1()

S1 = "catsanddog"
WORDDICT1 = ["cat", "cats", "and", "sand", "dog"]
EXPECTED1 = [
    "cat sand dog",
    "cats and dog"
]

S2 = "pineapplepenapple"
WORDDICT2 = ["apple", "pen", "applepen", "pine", "pineapple"]
EXPECTED2 = [
    "pine apple pen apple",
    "pine applepen apple",
    "pineapple pen apple"
]

S3 = "catsandog"
WORDDICT3 = ["cats", "dog", "sand", "and", "cat"]
EXPECTED3 = []


class TestWordBreakII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.wordBreak(S1, WORDDICT1))
        self.assertEqual(EXPECTED2, SOLUTION1.wordBreak(S2, WORDDICT2))
        self.assertEqual(EXPECTED3, SOLUTION1.wordBreak(S3, WORDDICT3))
