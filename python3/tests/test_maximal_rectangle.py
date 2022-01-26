from unittest import TestCase

from leetcodepy.maximal_rectangle import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

MATRIX1 = [
    ["1", "0", "1", "0", "0"],
    ["1", "0", "1", "1", "1"],
    ["1", "1", "1", "1", "1"],
    ["1", "0", "0", "1", "0"]
]
EXPECTED1 = 6

MATRIX2 = [["0"]]
EXPECTED2 = 0

MATRIX3 = [["1"]]
EXPECTED3 = 1


class TestMaximalRectangle(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maximalRectangle(MATRIX1))
        self.assertEqual(EXPECTED2, SOLUTION1.maximalRectangle(MATRIX2))
        self.assertEqual(EXPECTED3, SOLUTION1.maximalRectangle(MATRIX3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.maximalRectangle(MATRIX1))
        self.assertEqual(EXPECTED2, SOLUTION2.maximalRectangle(MATRIX2))
        self.assertEqual(EXPECTED3, SOLUTION2.maximalRectangle(MATRIX3))
