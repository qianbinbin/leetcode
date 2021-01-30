from unittest import TestCase

from leetcodepy.roman_to_integer import *

SOLUTION1 = Solution1()

S1 = "III"
EXPECTED1 = 3

S2 = "IV"
EXPECTED2 = 4

S3 = "IX"
EXPECTED3 = 9

S4 = "LVIII"
EXPECTED4 = 58

S5 = "MCMXCIV"
EXPECTED5 = 1994


class TestRomanToInteger(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.romanToInt(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.romanToInt(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.romanToInt(S3))
        self.assertEqual(EXPECTED4, SOLUTION1.romanToInt(S4))
        self.assertEqual(EXPECTED5, SOLUTION1.romanToInt(S5))
