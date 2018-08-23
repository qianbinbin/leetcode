from unittest import TestCase

from leetcodepy.integer_to_roman import *

solution1 = Solution1()

num1 = 3

expected1 = "III"

num2 = 4

expected2 = "IV"

num3 = 9

expected3 = "IX"

num4 = 58

expected4 = "LVIII"

num5 = 1994

expected5 = "MCMXCIV"


class TestIntegerToRoman(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.intToRoman(num1))
        self.assertEqual(expected2, solution1.intToRoman(num2))
        self.assertEqual(expected3, solution1.intToRoman(num3))
        self.assertEqual(expected4, solution1.intToRoman(num4))
        self.assertEqual(expected5, solution1.intToRoman(num5))
