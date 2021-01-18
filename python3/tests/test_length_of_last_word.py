from unittest import TestCase

from leetcodepy.length_of_last_word import *

solution1 = Solution1()

s = "Hello World"

expected = 5


class TestLengthOfLastWord(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.lengthOfLastWord(s))
