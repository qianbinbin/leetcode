from unittest import TestCase

from leetcodepy.word_break_ii import *

solution1 = Solution1()

s1 = "catsanddog"

wordDict1 = ["cat", "cats", "and", "sand", "dog"]

expected1 = [
    "cat sand dog",
    "cats and dog"
]

s2 = "pineapplepenapple"

wordDict2 = ["apple", "pen", "applepen", "pine", "pineapple"]

expected2 = [
    "pine apple pen apple",
    "pine applepen apple",
    "pineapple pen apple"
]

s3 = "catsandog"

wordDict3 = ["cats", "dog", "sand", "and", "cat"]

expected3 = []


class TestWordBreakII(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.wordBreak(s1, wordDict1))
        self.assertEqual(expected2, solution1.wordBreak(s2, wordDict2))
        self.assertEqual(expected3, solution1.wordBreak(s3, wordDict3))
