from unittest import TestCase

from leetcodepy.scramble_string import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S11 = "great"
S12 = "rgeat"
EXPECTED1 = True

S21 = "abcde"
S22 = "caebd"
EXPECTED2 = False

S31 = "a"
S32 = "a"
EXPECTED3 = True


class TestScrambleString(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isScramble(S11, S12))
        self.assertEqual(EXPECTED2, SOLUTION1.isScramble(S21, S22))
        self.assertEqual(EXPECTED3, SOLUTION1.isScramble(S31, S32))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.isScramble(S11, S12))
        self.assertEqual(EXPECTED2, SOLUTION2.isScramble(S21, S22))
        self.assertEqual(EXPECTED3, SOLUTION2.isScramble(S31, S32))
