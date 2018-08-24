from unittest import TestCase

from leetcodepy.gray_code import *

solution1 = Solution1()

n1 = 2

expected1 = [0, 1, 3, 2]

n2 = 0

expected2 = [0]


class TestGrayCode(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.grayCode(n1))
        self.assertListEqual(expected2, solution1.grayCode(n2))
