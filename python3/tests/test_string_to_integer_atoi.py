from unittest import TestCase

from leetcodepy.string_to_integer_atoi import *

solution1 = Solution1()

s1 = "42"
expected1 = 42

s2 = "   -42"

expected2 = -42

s3 = "4193 with words"

expected3 = 4193

s4 = "words and 987"

expected4 = 0

s5 = "-91283472332"

expected5 = -2147483648


class TestStringToIntegerAtoi(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.myAtoi(s1))
        self.assertEqual(expected2, solution1.myAtoi(s2))
        self.assertEqual(expected3, solution1.myAtoi(s3))
        self.assertEqual(expected4, solution1.myAtoi(s4))
        self.assertEqual(expected5, solution1.myAtoi(s5))
