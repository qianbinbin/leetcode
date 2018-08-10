from unittest import TestCase

from leetcodepy.maximal_rectangle import *

solution1 = Solution1()

matrix = [
    ["1", "0", "1", "0", "0"],
    ["1", "0", "1", "1", "1"],
    ["1", "1", "1", "1", "1"],
    ["1", "0", "0", "1", "0"]
]

expected = 6


class TestMaximalRectangle(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.maximalRectangle(matrix))
