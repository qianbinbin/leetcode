from unittest import TestCase

from leetcodepy.word_search import *

SOLUTION1 = Solution1()

BOARD1 = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
]
WORD1 = "ABCCED"
EXPECTED1 = True

BOARD2 = BOARD1
WORD2 = "SEE"
EXPECTED2 = True

BOARD3 = BOARD1
WORD3 = "ABCB"
EXPECTED3 = False


class TestWordSearch(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.exist(BOARD1, WORD1))
        self.assertEqual(EXPECTED2, SOLUTION1.exist(BOARD2, WORD2))
        self.assertEqual(EXPECTED3, SOLUTION1.exist(BOARD3, WORD3))
