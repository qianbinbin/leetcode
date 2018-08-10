from unittest import TestCase

from leetcodepy.zigzag_conversion import *

solution1 = Solution1()

s1 = "PAYPALISHIRING"

numRows1 = 3

expected1 = "PAHNAPLSIIGYIR"

s2 = "PAYPALISHIRING"

numRows2 = 4

expected2 = "PINALSIGYAHRPI"


class TestZigZagConversion(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.convert(s1, numRows1))
        self.assertEqual(expected2, solution1.convert(s2, numRows2))
