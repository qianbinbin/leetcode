from unittest import TestCase

from leetcodepy.multiply_strings import *

solution1 = Solution1()

num11 = "2"

num12 = "3"

expected1 = "6"

num21 = "123"

num22 = "456"

expected2 = "56088"


class TestMultiplyStrings(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.multiply(num11, num12))
        self.assertEqual(expected2, solution1.multiply(num21, num22))
