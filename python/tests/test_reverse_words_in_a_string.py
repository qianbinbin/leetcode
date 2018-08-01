from unittest import TestCase

from reverse_words_in_a_string import *

solution1 = Solution1()

s = "the sky is blue"

expected = "blue is sky the"


class TestReverseWordsInAString(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.reverseWords(s))
