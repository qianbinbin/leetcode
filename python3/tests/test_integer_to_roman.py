from unittest import TestCase

from leetcodepy.integer_to_roman import *

SOLUTION1 = Solution1()

NUM1 = 3
EXPECTED1 = "III"

NUM2 = 4
EXPECTED2 = "IV"

NUM3 = 9
EXPECTED3 = "IX"

NUM4 = 58
EXPECTED4 = "LVIII"

NUM5 = 1994
EXPECTED5 = "MCMXCIV"


class TestIntegerToRoman(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.intToRoman(NUM1))
        self.assertEqual(EXPECTED2, SOLUTION1.intToRoman(NUM2))
        self.assertEqual(EXPECTED3, SOLUTION1.intToRoman(NUM3))
        self.assertEqual(EXPECTED4, SOLUTION1.intToRoman(NUM4))
        self.assertEqual(EXPECTED5, SOLUTION1.intToRoman(NUM5))
