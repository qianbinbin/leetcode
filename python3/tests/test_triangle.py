from unittest import TestCase

from leetcodepy.triangle import *

solution1 = Solution1()

triangle = [
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]

expected = 11


class TestTriangle(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.minimumTotal(triangle))
