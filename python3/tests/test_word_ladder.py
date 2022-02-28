from unittest import TestCase

from leetcodepy.word_ladder import *

SOLUTION1 = Solution1()

BEGINWORD1 = "hit"
ENDWORD1 = "cog"
WORDLIST1 = ["hot", "dot", "dog", "lot", "log", "cog"]
EXPECTED1 = 5

BEGINWORD2 = "hit"
ENDWORD2 = "cog"
WORDLIST2 = ["hot", "dot", "dog", "lot", "log"]
EXPECTED2 = 0


class TestWordLadder(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.ladderLength(BEGINWORD1, ENDWORD1, WORDLIST1))
        self.assertEqual(EXPECTED2, SOLUTION1.ladderLength(BEGINWORD2, ENDWORD2, WORDLIST2))
