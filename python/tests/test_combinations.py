from unittest import TestCase

from leetcodepy.combinations import *

solution1 = Solution1()

n = 4

k = 2

expected = [
    [1, 2],
    [1, 3],
    [1, 4],
    [2, 3],
    [2, 4],
    [3, 4]
]


class TestCombinations(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.combine(n, k))
