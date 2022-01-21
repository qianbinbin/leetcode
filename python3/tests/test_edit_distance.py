from unittest import TestCase

from leetcodepy.edit_distance import *

SOLUTION1 = Solution1()

WORD11 = "horse"
WORD12 = "ros"
EXPECTED1 = 3

WORD21 = "intention"
WORD22 = "execution"
EXPECTED2 = 5


class TestEditDistance(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.minDistance(WORD11, WORD12))
        self.assertEqual(EXPECTED2, SOLUTION1.minDistance(WORD21, WORD22))
