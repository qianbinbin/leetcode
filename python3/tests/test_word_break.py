from unittest import TestCase

from leetcodepy.word_break import *

SOLUTION1 = Solution1()

S1 = "leetcode"
WORDDICT1 = ["leet", "code"]
EXPECTED1 = True

S2 = "applepenapple"
WORDDICT2 = ["apple", "pen"]
EXPECTED2 = True

S3 = "catsandog"
WORDDICT3 = ["cats", "dog", "sand", "and", "cat"]
EXPECTED3 = False


class TestWordBreak(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.wordBreak(S1, WORDDICT1))
        self.assertEqual(EXPECTED2, SOLUTION1.wordBreak(S2, WORDDICT2))
        self.assertEqual(EXPECTED3, SOLUTION1.wordBreak(S3, WORDDICT3))
