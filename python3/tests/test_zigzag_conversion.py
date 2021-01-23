from unittest import TestCase

from leetcodepy.zigzag_conversion import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

S1 = "PAYPALISHIRING"
NUM_ROWS1 = 3
EXPECTED1 = "PAHNAPLSIIGYIR"

S2 = "PAYPALISHIRING"
NUM_ROWS2 = 4
EXPECTED2 = "PINALSIGYAHRPI"

S3 = "A"
NUM_ROWS3 = 1
EXPECTED3 = "A"


class TestZigZagConversion(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.convert(S1, NUM_ROWS1))
        self.assertEqual(EXPECTED2, SOLUTION1.convert(S2, NUM_ROWS2))
        self.assertEqual(EXPECTED3, SOLUTION1.convert(S3, NUM_ROWS3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.convert(S1, NUM_ROWS1))
        self.assertEqual(EXPECTED2, SOLUTION2.convert(S2, NUM_ROWS2))
        self.assertEqual(EXPECTED3, SOLUTION2.convert(S3, NUM_ROWS3))
