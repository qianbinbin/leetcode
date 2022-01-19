from unittest import TestCase

from leetcodepy.add_binary import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

A1 = "11"
B1 = "1"
EXPECTED1 = "100"

A2 = "1010"
B2 = "1011"
EXPECTED2 = "10101"


class TestAddBinary(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.addBinary(A1, B1))
        self.assertEqual(EXPECTED2, SOLUTION1.addBinary(A2, B2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.addBinary(A1, B1))
        self.assertEqual(EXPECTED2, SOLUTION2.addBinary(A2, B2))
