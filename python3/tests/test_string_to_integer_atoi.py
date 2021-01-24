from unittest import TestCase

from leetcodepy.string_to_integer_atoi import *

SOLUTION1 = Solution1()

S1 = "42"
EXPECTED1 = 42

S2 = "   -42"
EXPECTED2 = -42

S3 = "4193 with words"
EXPECTED3 = 4193

S4 = "words and 987"
EXPECTED4 = 0

S5 = "-91283472332"
EXPECTED5 = -2147483648


class TestStringToIntegerAtoi(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.myAtoi(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.myAtoi(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.myAtoi(S3))
        self.assertEqual(EXPECTED4, SOLUTION1.myAtoi(S4))
        self.assertEqual(EXPECTED5, SOLUTION1.myAtoi(S5))
