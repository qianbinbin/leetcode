from unittest import TestCase

from leetcodepy.candy import *

SOLUTION1 = Solution1()

RATINGS1 = [1, 0, 2]
EXPECTED1 = 5

RATINGS2 = [1, 2, 2]
EXPECTED2 = 4


class TestCandy(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.candy(RATINGS1))
        self.assertEqual(EXPECTED2, SOLUTION1.candy(RATINGS2))
