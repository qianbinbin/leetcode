from unittest import TestCase

from leetcodepy.plus_one import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

DIGITS1 = [1, 2, 3]
EXPECTED1 = [1, 2, 4]

DIGITS2 = [4, 3, 2, 1]
EXPECTED2 = [4, 3, 2, 2]

DIGITS3 = [9]
EXPECTED3 = [1]


class TestPlusOne(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.plusOne(DIGITS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.plusOne(DIGITS2))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.plusOne(DIGITS1))
        self.assertListEqual(EXPECTED2, SOLUTION2.plusOne(DIGITS2))
