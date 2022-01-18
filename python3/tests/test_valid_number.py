from unittest import TestCase

from leetcodepy.valid_number import *

SOLUTION1 = Solution1()

S1 = "0"
EXPECTED1 = True

S2 = "e"
EXPECTED2 = False

S3 = "."
EXPECTED3 = False


class TestValidNumber(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isNumber(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.isNumber(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.isNumber(S3))
