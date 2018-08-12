from unittest import TestCase

from leetcodepy.add_binary import *

solution1 = Solution1()

a1 = "11"

b1 = "1"

expected1 = "100"

a2 = "1010"

b2 = "1011"

expected2 = "10101"


class TestAddBinary(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.addBinary(a1, b1))
        self.assertEqual(expected2, solution1.addBinary(a2, b2))
