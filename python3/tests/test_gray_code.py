from unittest import TestCase

from leetcodepy.gray_code import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

N1 = 2
EXPECTED1 = [0, 1, 3, 2]

N2 = 1
EXPECTED2 = [0, 1]


class TestGrayCode(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.grayCode(N1))
        self.assertListEqual(EXPECTED2, SOLUTION1.grayCode(N2))

    def test2(self):
        self.assertListEqual(EXPECTED1, SOLUTION2.grayCode(N1))
        self.assertListEqual(EXPECTED2, SOLUTION2.grayCode(N2))
