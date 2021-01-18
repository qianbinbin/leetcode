from unittest import TestCase

from leetcodepy.edit_distance import *

solution1 = Solution1()

word11 = "horse"

word12 = "ros"

expected1 = 3

word21 = "intention"

word22 = "execution"

expected2 = 5


class TestEditDistance(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.minDistance(word11, word12))
        self.assertEqual(expected2, solution1.minDistance(word21, word22))
