from unittest import TestCase

from leetcodepy.word_ladder_ii import *

SOLUTION1 = Solution1()

BEGINWORD1 = "hit"
ENDWORD1 = "cog"
WORDLIST1 = ["hot", "dot", "dog", "lot", "log", "cog"]
EXPECTED1 = [
    ["hit", "hot", "dot", "dog", "cog"],
    ["hit", "hot", "lot", "log", "cog"]
]

BEGINWORD2 = "hit"
ENDWORD2 = "cog"
WORDLIST2 = ["hot", "dot", "dog", "lot", "log"]
EXPECTED2 = []


class TestWordLadderII(TestCase):
    def test1(self):
        actual1 = set(tuple(_) for _ in SOLUTION1.findLadders(BEGINWORD1, ENDWORD1, WORDLIST1))
        expected1 = set(tuple(_) for _ in EXPECTED1)
        self.assertSetEqual(expected1, actual1)

        actual2 = set(tuple(_) for _ in SOLUTION1.findLadders(BEGINWORD2, ENDWORD2, WORDLIST2))
        expected2 = set(tuple(_) for _ in EXPECTED2)
        self.assertSetEqual(expected2, actual2)
