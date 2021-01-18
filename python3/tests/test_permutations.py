from unittest import TestCase

from leetcodepy.permutations import *

solution1 = Solution1()

nums = [1, 2, 3]

expected = [
    [1, 2, 3],
    [1, 3, 2],
    [2, 1, 3],
    [2, 3, 1],
    [3, 1, 2],
    [3, 2, 1]
]


class TestPermutations(TestCase):
    def test1(self):
        self.assertListEqual(expected, solution1.permute(nums))
