from unittest import TestCase

from leetcodepy.multiply_strings import *

SOLUTION1 = Solution1()

NUM11 = "2"
NUM12 = "3"
EXPECTED1 = "6"

NUM21 = "123"
NUM22 = "456"
EXPECTED2 = "56088"


class TestMultiplyStrings(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.multiply(NUM11, NUM12))
        self.assertEqual(EXPECTED2, SOLUTION1.multiply(NUM21, NUM22))
