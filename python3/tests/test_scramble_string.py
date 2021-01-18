from unittest import TestCase

from leetcodepy.scramble_string import *

solution1 = Solution1()

s11 = "great"

s12 = "rgeat"

s21 = "abcde"

s22 = "caebd"


class TestScrambleString(TestCase):
    def test1(self):
        self.assertTrue(solution1.isScramble(s11, s12))
        self.assertFalse(solution1.isScramble(s21, s22))
