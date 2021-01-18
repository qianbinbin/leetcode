from unittest import TestCase

from leetcodepy.gray_code import *

solution1 = Solution1()

solution2 = Solution2()

n1 = 2

expected1 = [0, 1, 3, 2]

n2 = 0

expected2 = [0]


class TestGrayCode(TestCase):
    def test1(self):
        self.assertListEqual(expected1, solution1.grayCode(n1))
        self.assertListEqual(expected2, solution1.grayCode(n2))

    def test2(self):
        self.assertListEqual(expected1, solution2.grayCode(n1))
        self.assertListEqual(expected2, solution2.grayCode(n2))
