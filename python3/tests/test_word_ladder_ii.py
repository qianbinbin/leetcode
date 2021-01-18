from unittest import TestCase

from leetcodepy.word_ladder_ii import *

solution1 = Solution1()

beginWord1 = "hit"

endWord1 = "cog"

wordList1 = ["hot", "dot", "dog", "lot", "log", "cog"]

expected1 = [
    ["hit", "hot", "dot", "dog", "cog"],
    ["hit", "hot", "lot", "log", "cog"]
]

beginWord2 = "hit"

endWord2 = "cog"

wordList2 = ["hot", "dot", "dog", "lot", "log"]

expected2 = []


class TestWordLadderII(TestCase):
    def test1(self):
        actual1 = set(tuple(l) for l in solution1.findLadders(beginWord1, endWord1, wordList1))
        e1 = set(tuple(l) for l in expected1)
        self.assertSetEqual(e1, actual1)
        actual2 = set(tuple(l) for l in solution1.findLadders(beginWord2, endWord2, wordList2))
        e2 = set(tuple(l) for l in expected2)
        self.assertSetEqual(e2, actual2)
