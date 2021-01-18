from unittest import TestCase

from leetcodepy.candy import *

solution1 = Solution1()

ratings1 = [1, 0, 2]

expected1 = 5

ratings2 = [1, 2, 2]

expected2 = 4


class TestCandy(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.candy(ratings1))
        self.assertEqual(expected2, solution1.candy(ratings2))
