from unittest import TestCase

from leetcodepy.word_ladder import *

solution1 = Solution1()

beginWord1 = "hit"

endWord1 = "cog"

wordList1 = ["hot", "dot", "dog", "lot", "log", "cog"]

expected1 = 5

beginWord2 = "hit"

endWord2 = "cog"

wordList2 = ["hot", "dot", "dog", "lot", "log"]

expected2 = 0


class TestWordLadder(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.ladderLength(beginWord1, endWord1, wordList1))
        self.assertEqual(expected2, solution1.ladderLength(beginWord2, endWord2, wordList2))
