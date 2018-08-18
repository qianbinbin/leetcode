from unittest import TestCase

from leetcodepy.letter_combinations_of_a_phone_number import *

solution1 = Solution1()

digits = "23"

expected = ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]


class TestLetterCombinationsOfAPhoneNumber(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.letterCombinations(digits))
