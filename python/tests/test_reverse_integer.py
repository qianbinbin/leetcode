from unittest import TestCase

from leetcodepy.reverse_integer import *

solution1 = Solution1()

x1 = 123

expected1 = 321

x2 = -123

expected2 = -321

x3 = 120

expected3 = 21


class TestReverseInteger(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.reverse(x1))
        self.assertEqual(expected2, solution1.reverse(x2))
        self.assertEqual(expected3, solution1.reverse(x3))
