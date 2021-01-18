from unittest import TestCase

from leetcodepy.word_search import *

solution1 = Solution1()

board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
]

word1 = "ABCCED"

word2 = "SEE"

word3 = "ABCB"


class TestWordSearch(TestCase):
    def test1(self):
        self.assertTrue(solution1.exist(board, word1))
        self.assertTrue(solution1.exist(board, word2))
        self.assertFalse(solution1.exist(board, word3))
