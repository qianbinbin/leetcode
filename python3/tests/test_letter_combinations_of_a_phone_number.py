from unittest import TestCase

from leetcodepy.letter_combinations_of_a_phone_number import *

SOLUTION1 = Solution1()

DIGITS1 = "23"
EXPECTED1 = ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

DIGITS2 = ""
EXPECTED2 = []

DIGITS3 = "2"
EXPECTED3 = ["a", "b", "c"]


class TestLetterCombinationsOfAPhoneNumber(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.letterCombinations(DIGITS1))
        self.assertEqual(EXPECTED2, SOLUTION1.letterCombinations(DIGITS2))
        self.assertEqual(EXPECTED3, SOLUTION1.letterCombinations(DIGITS3))
