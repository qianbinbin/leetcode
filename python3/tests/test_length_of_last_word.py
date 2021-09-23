from unittest import TestCase

from leetcodepy.length_of_last_word import *

SOLUTION1 = Solution1()

S1 = "Hello World"
EXPECTED1 = 5


class TestLengthOfLastWord(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.lengthOfLastWord(S1))
