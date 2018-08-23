from unittest import TestCase

from leetcodepy.word_break import *

solution1 = Solution1()

s1 = "leetcode"

wordDict1 = ["leet", "code"]

s2 = "applepenapple"

wordDict2 = ["apple", "pen"]

s3 = "catsandog"

wordDict3 = ["cats", "dog", "sand", "and", "cat"]


class TestWordBreak(TestCase):
    def test1(self):
        self.assertTrue(solution1.wordBreak(s1, wordDict1))
        self.assertTrue(solution1.wordBreak(s2, wordDict2))
        self.assertFalse(solution1.wordBreak(s3, wordDict3))
