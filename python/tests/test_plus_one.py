from unittest import TestCase

from leetcodepy.plus_one import *

solution1 = Solution1()

digits1 = [1, 2, 3]

expected1 = [1, 2, 4]

digits2 = [4, 3, 2, 1]

expected2 = [4, 3, 2, 2]


class TestPlusOne(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.plusOne(digits1))
        self.assertListEqual(expected2, solution1.plusOne(digits2))
