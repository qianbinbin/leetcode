from unittest import TestCase

from leetcodepy.roman_to_integer import *

solution1 = Solution1()

s1 = "III"

expected1 = 3

s2 = "IV"

expected2 = 4

s3 = "IX"

expected3 = 9

s4 = "LVIII"

expected4 = 58

s5 = "MCMXCIV"

expected5 = 1994


class TestRomanToInteger(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.romanToInt(s1))
        self.assertEqual(expected2, solution1.romanToInt(s2))
        self.assertEqual(expected3, solution1.romanToInt(s3))
        self.assertEqual(expected4, solution1.romanToInt(s4))
        self.assertEqual(expected5, solution1.romanToInt(s5))
